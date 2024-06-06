#include "Snow.h"
#include <iostream>

void Snow::add_point(Points a) {
    vertices.push_back(a);
}

void Snow::draw() {
    if (vertices.size() == 0) {
        return;
    }
    glColor3f(112.0 / 255, 86.0 / 255, 151.0 / 255);
    glPointSize(10.0);
    glBegin(GL_POINTS);
    for (auto vertex: vertices) {
        float nwv[2] = {vertex.x, vertex.y};
        glVertex2fv(nwv);
    }
    glEnd();
    if (!finished) {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINE_STRIP);
        for (auto vertex: vertices) {
            float nwv[2] = {vertex.x, vertex.y};
            glVertex2fv(nwv);
        }
        float nwv[2] = {vertices[0].x, vertices[0].y};
        glVertex2fv(nwv);
        glEnd();
        return;
    }
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (auto vertex: vertices) {
        float nwv[2] = {vertex.x, vertex.y};
        glVertex2fv(nwv);
    }
    glEnd();
}