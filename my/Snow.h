#ifndef SNOW_H
#define SNOW_H

#include "GLFW/glfw3.h"
#include <bits/stdc++.h>
#include "Points.h"

class Snow {
public:
    std::vector<Points> vertices;
    bool finished;

    Snow() {
        vertices.clear();
        finished = false;
    }

    void add_point(Points a);

    void draw();
};

#endif