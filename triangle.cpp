#include "triangle.h"
#include <iostream>
#include <cassert>
triangle::triangle(const point& p1_, const point& p2_, const point& p3_): p1(p1_), p2(p2_), p3(p3_) {}

triangle::triangle(std::istream &is) {
    is >> p1 >> p2 >> p3;
}

point triangle::center() const {
    point cen{};
    cen.x = (p1.x + p2.x + p3.x)/3;
    cen.y = (p1.y + p2.y + p3.y)/3;
    return cen;
}

double triangle::area() const {
    double p = (dist(p1, p2) + dist(p1, p3) + dist(p2, p3))/2;
    return sqrt(p * (p - dist(p1, p2) ) * (p - dist(p1, p3) ) * (p - dist(p2, p3) ));
}

void triangle::print(std::ostream &os) const {
    os << "Triangle [" << p1 << ","<< p2 << ","<< p3 << "]";
}

bool triangle::is_figure() const {
    vec p1_p2 = vector(p1, p2);
    vec p1_p3 = vector(p1, p3);
    return ((p1_p2.x) / (p1_p3.x) != (p1_p2.y) / (p1_p3.y)) || (p1 == p3 ) || (p1 == p2) || (p2 == p3);
}



