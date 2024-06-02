#include "Snow.h"

void Snow::draw() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (auto vertex: vertices) {
        float nwv[2] = {vertex.x, vertex.y};
        glVertex2fv(nwv);
    }
    glEnd();
    glColor3f(0.0, 0.5, 0.3);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    for (auto vertex: vertices) {
        float nwv[2] = {vertex.x, vertex.y};
        glVertex2fv(nwv);
    }
    glEnd();
}