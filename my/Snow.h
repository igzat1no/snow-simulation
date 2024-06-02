#ifndef SNOW_H
#define SNOW_H

#include "GLFW/glfw3.h"
#include <bits/stdc++.h>
#include "Points.h"

class Snow {
    public:
    std::vector<Points> vertices;

    void add_point(Points a) {
        vertices.push_back(a);
    }

    void draw();
};

#endif