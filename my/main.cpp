#include "GLFW/glfw3.h"
#include <bits/stdc++.h>
#include "Snow.h"

const int width = 800;
const int height = 600;

bool need_update = false;
std::vector<Snow*> vec;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action != GLFW_RELEASE) return;
    if (key == GLFW_KEY_ENTER)
    {
        vec.back()->finished = true;
        vec.push_back(new Snow());
        need_update = true;
    }
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        if (vec.size() == 0) {
            vec.push_back(new Snow());
        }
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        xpos = xpos / width * 2 - 1;
        ypos = 1 - ypos / height * 2;
        Points nwp = Points(xpos, ypos);
        vec.back()->add_point(nwp);

        need_update = true;
    }
}

void draw_screen() {
    for (auto &i : vec) {
        i->draw();
    }
}

int main()
{
    srand(time(0));
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(width, height, "Snow simulation", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    while (!glfwWindowShouldClose(window)) {
        if (need_update) {
	        glClearColor(0, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            draw_screen();
            need_update = false;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
