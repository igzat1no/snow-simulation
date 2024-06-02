#ifndef POINTS_H
#define POINTS_H

class Points {
    public:
    double x, y;

    Points(): x(0), y(0) {}
    Points(double _x, double _y): x(_x), y(_y) {}
    Points(Points& ano): x(ano.x), y(ano.y) {}

};

#endif