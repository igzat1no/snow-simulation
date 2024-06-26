#include "main.h"

using namespace std;

//Old and new time values for each timestep
double old_time, new_time = glfwGetTime();
bool dirty_buffer = true;
int frame_count = 0,
	bsize = 3*WIN_SIZE*WIN_SIZE;
unsigned char* img_buffer;

//Circle drawing
int circle_draw_state = 0;
Vector2f circle_origin;

//Simulation data
bool simulating = false;
vector<Shape*> snow_shapes;
int point_size;
PointCloud* snow = NULL;
PointCloud* snow2 = NULL;
PointCloud* snow3 = NULL;
Grid* grid;

int main(int argc, char** argv){
	srand(time(NULL));
	
	//Create GLFW window
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(WIN_SIZE, WIN_SIZE, "Snow Simulator", NULL, NULL);
	if (!window){
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_callback);
	
	//Center window on screen
	const GLFWvidmode* monitor = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(window, (monitor->width-WIN_SIZE)/2, (monitor->height-WIN_SIZE)/2);
	
	//Setup OpenGL context
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, WIN_SIZE, WIN_SIZE);
	glOrtho(0, WIN_METERS, 0, WIN_METERS, 0, 1);
	
	//Drawing & event loop
	//Create directory to save buffers in
#if SCREENCAST
	mkdir(SCREENCAST_DIR,0777);
	FreeImage_Initialise();
	img_buffer = new unsigned char[bsize];
#endif
	
	/*
	Shape* snowball = new Shape();
	const int segments = 18;
	//Cool circle algorithm: http://slabode.exofire.net/circle_draw.shtml
	circle_origin = Vector2f(.5,.65);
	float radius = .15,
		theta = 6.283185307 / (float) segments,
		tan_fac = tan(theta),
		cos_fac = cos(theta),
		x = radius,
		y = 0;
	for (int i=0; i<segments; i++){
		snowball->addPoint(x+circle_origin[0], y+circle_origin[1]);
		float flip_x = -y, flip_y = x;
		x += flip_x*tan_fac;
		y += flip_y*tan_fac;
		x *= cos_fac;
		y *= cos_fac;
	}
	snow_shapes.push_back(snowball);
	start_simulation();
	//*/
	//start_simulation();
	
	while (!glfwWindowShouldClose(window)){
		if (dirty_buffer){
			redraw();
			dirty_buffer = false;
#if SCREENCAST
			if (simulating)
				save_buffer(frame_count++);
#endif
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//Exit
#if SCREENCAST
	FreeImage_DeInitialise();
	delete[] img_buffer;
#endif
	
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
	return 0;
	//Setup OpenGL context
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, WIN_SIZE, WIN_SIZE);
	glOrtho(0, WIN_METERS, 0, WIN_METERS, 0, 1);
	
	//Drawing & event loop
	//Create directory to save buffers in
#if SCREENCAST
	mkdir(SCREENCAST_DIR,0777);
	FreeImage_Initialise();
	img_buffer = new unsigned char[bsize];
#endif
	start_simulation();
	
	while (!glfwWindowShouldClose(window)){
		if (dirty_buffer){
			redraw();
			dirty_buffer = false;
#if SCREENCAST
			if (simulating)
				save_buffer(frame_count++);
#endif
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//Exit
#if SCREENCAST
	FreeImage_DeInitialise();
	delete[] img_buffer;
#endif
	
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
	return 0;
}
//Print all errors to console
static void error_callback(int error, const char* description){
	printf("\nError: %s",description);
}
//Key listener
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if (action != GLFW_RELEASE)
		return;
    switch (key){
		case GLFW_KEY_F12:
			//Create default simulation loop
			start_simulation();
			break;
		case GLFW_KEY_ESCAPE:
			remove_all_shapes();
			if (snow != NULL) delete snow;
			if (snow2 != NULL) delete snow2;
			if (snow3 != NULL) delete snow3;
			if (simulating)
				simulating = false;
			dirty_buffer = true;
			break;
		case GLFW_KEY_ENTER:
			if (!simulating)
				create_new_shape();
			break;
		case GLFW_KEY_C:
			if (!simulating)
				circle_draw_state = 1;
			break;
	}
}
//Mouse listener
void mouse_callback(GLFWwindow* window, int btn, int action, int mods){
	if (action == GLFW_RELEASE && btn == GLFW_MOUSE_BUTTON_LEFT){
		//Create a snow shape, if none exist
		if (snow_shapes.empty())
			create_new_shape();
		//Add vertex to the shape
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		//Convert screen coordinates to world
		y = (1-y/WIN_SIZE)*WIN_METERS;
		x = x/WIN_SIZE*WIN_METERS;
		//Regular point
		switch (circle_draw_state){
			//Regular point
			case 0:
				snow_shapes.back()->addPoint(x, y);
				break;
			//Circle origin
			case 1:
				circle_origin.setData(x, y);
				circle_draw_state = 2;
				break;
			//Circle radius
			case 2:
				const int segments = 18;
				//Cool circle algorithm: http://slabode.exofire.net/circle_draw.shtml
				float x_dif = circle_origin[0] - x,
					y_dif = circle_origin[1] - y,
					radius = sqrt(x_dif*x_dif + y_dif*y_dif),
					theta = 6.283185307 / (float) segments,
					tan_fac = tan(theta),
					cos_fac = cos(theta),
					x = radius,
					y = 0;
				for (int i=0; i<segments; i++){
					snow_shapes.back()->addPoint(x+circle_origin[0], y+circle_origin[1]);
					float flip_x = -y, flip_y = x;
					x += flip_x*tan_fac;
					y += flip_y*tan_fac;
					x *= cos_fac;
					y *= cos_fac;
				}
				circle_draw_state = 0;
				break;
		}
		dirty_buffer = true;
	}
}

//Creates another snow shape for editing
void create_new_shape(){
	snow_shapes.push_back(new Shape());
}
//Removes all snow shapes
void remove_all_shapes(){
	for (int i=0, len=snow_shapes.size(); i<len; i++)
		delete snow_shapes[i];
	snow_shapes.clear();
}

//Simulation
//float TIMESTEP;
void start_simulation(){
	/* Multiple snow shapes
	snow_shapes.push_back(generateSnowball(Vector2f(1.1,1.1), .27));
	snow = PointCloud::createShape(snow_shapes, Vector2f(10, 10));
	remove_all_shapes();
	snow_shapes.push_back(generateSnowball(Vector2f(1.1,.9), .25));
	PointCloud* snow2 = PointCloud::createShape(snow_shapes, Vector2f(11, -2));
	remove_all_shapes();
	snow_shapes.push_back(generateSnowball(Vector2f(.87,1.05), .28));
	PointCloud* snow3 = PointCloud::createShape(snow_shapes, Vector2f(-11, 5));
	snow->merge(*snow2);
	snow->merge(*snow3);
	*/
	//Convert drawn shapes to snow particles
	snow = PointCloud::createShape(snow_shapes, Vector2f(2, 0));
	//If there are no shapes, we can't do a simulation
	if (snow == NULL) return;
	point_size = 6;
	
	//Computational grid
	grid = new Grid(Vector2f(0), Vector2f(WIN_METERS, WIN_METERS), Vector2f(64), snow);
	//We need to estimate particle volumes before we start
	grid->initializeMass();	
	grid->calculateVolumes();
	
	pthread_t sim_thread;
	pthread_create(&sim_thread, NULL, simulate, NULL);
}
void *simulate(void *args){
	simulating = true;
	struct timespec delay;
	delay.tv_sec = 0;
	clock_t start = clock(), end;
	cout << "Starting simulation..." << endl;
	Vector2f gravity = Vector2f(0, GRAVITY);
	
	float cum_sum = 0;
	int iter = 0;
	while (simulating && ++iter > 0){
		TIMESTEP = adaptive_timestep();
		cum_sum += TIMESTEP;
		
		//Initialize FEM grid
		grid->initializeMass();
		grid->initializeVelocities();
		//Compute grid velocities
		grid->explicitVelocities(gravity);
#if ENABLE_IMPLICIT
		if (IMPLICIT_RATIO > 0)
			grid->implicitVelocities();
#endif
		//Map back to particles
		grid->updateVelocities();
		//Update particle data
		snow->update();
		
		//Redraw snow
		if (!LIMIT_FPS || cum_sum >= FRAMERATE){
			dirty_buffer = true;
			cum_sum -= FRAMERATE;
		}
		//Realtime visualization (approximate)
#if REALTIME
		clock_t end_new = clock()+15;
		float diff = (end_new-end)/(float) CLOCKS_PER_SEC;
		end = end_new;
		if (diff < TIMESTEP){
			delay.tv_nsec = 1/(TIMESTEP-diff);
			nanosleep(&delay, NULL);
		}
		//Slow motion playback
		delay.tv_nsec = SLO_MO;
		nanosleep(&delay, NULL);
#endif
	}

	cout << "Simulation complete: " << (clock()-start)/(float) CLOCKS_PER_SEC << " seconds\n" << endl;
	simulating = false;
	pthread_exit(NULL);
}
float adaptive_timestep(){
	float max_vel = snow->max_velocity, f;
	if (max_vel > 1e-8){
		//We should really take the min(cellsize) I think, if the grid is not square
		float dt = CFL * grid->cellsize[0]/sqrt(max_vel);
		f = dt > FRAMERATE ? FRAMERATE : dt;
	}
	else f = FRAMERATE;
	return f > MAX_TIMESTEP ? MAX_TIMESTEP : f;
}

void redraw(){
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	if (simulating){
		//Grid nodes
                /*
		glPointSize(1);
		glColor3f(0, .7, 1);
		glBegin(GL_POINTS);
		for (int i=0; i<grid->size[0]; i++){
			for (int j=0; j<grid->size[1]; j++)
				glVertex2fv((grid->origin+grid->cellsize*Vector2f(i, j)).data);
		}
		glEnd();
                 */

		//Snow particles
		if (SUPPORTS_POINT_SMOOTH)
			glEnable(GL_POINT_SMOOTH);
		glPointSize(point_size);
		glBegin(GL_POINTS);
		for (int i=0; i<snow->size; i++){
			Particle& p = snow->particles[i];
			//We can use the particle's density to vary color
			float contrast = 0.6;
			float density = p.density/DENSITY*contrast;
			density += 1-contrast;
			glColor3f(density, density, density);
			glVertex2fv(p.position.data);
		}
		glEnd();
		if (SUPPORTS_POINT_SMOOTH)
			glDisable(GL_POINT_SMOOTH);
	}
	else{
		if (circle_draw_state == 2){
			glPointSize(10);
			glColor3f(1, 0, 0);
			glBegin(GL_POINTS);
				glVertex2fv(circle_origin.data);
			glEnd();
		}
		for (int i=0, l=snow_shapes.size(); i<l; i++)
			snow_shapes[i]->draw();
	}
}
#if SCREENCAST
void save_buffer(int time){
	FILE *file;
	char fname[32];
	
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	sprintf(fname, "%st_%04d.png", SCREENCAST_DIR, time);
	printf("%s\n", fname);
	
	//Copy the image to buffer
	glReadBuffer(GL_BACK_LEFT);
	glReadPixels(0, 0, WIN_SIZE, WIN_SIZE, GL_BGR, GL_UNSIGNED_BYTE, img_buffer);
	FIBITMAP* img = FreeImage_ConvertFromRawBits(
		img_buffer, WIN_SIZE, WIN_SIZE, 3*WIN_SIZE,
		24, 0xFF0000, 0x00FF00, 0x0000FF, false
	);
	FreeImage_Save(FIF_PNG, img, fname, 0);
	FreeImage_Unload(img);
}
#endif

Shape* generateSnowball(Vector2f origin, float radius){
	Shape* snowball = new Shape();
	const int segments = 18;
	//Cool circle algorithm: http://slabode.exofire.net/circle_draw.shtml
	float theta = 6.283185307 / (float) segments,
		tan_fac = tan(theta),
		cos_fac = cos(theta),
		x = radius,
		y = 0;
	for (int i=0; i<segments; i++){
		snowball->addPoint(x+origin[0], y+origin[1]);
		float flip_x = -y, flip_y = x;
		x += flip_x*tan_fac;
		y += flip_y*tan_fac;
		x *= cos_fac;
		y *= cos_fac;
	}
	return snowball;
}