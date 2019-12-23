#include "square.h"
#include<iostream>
#include<cmath>
square::square(point p1_, point p2_, point p3_, point p4_): p1(p1_), p2(p2_), p3(p3_), p4(p4_) {
    this->sort();
    if(!is_figure()) {
        throw std::invalid_argument(" isn't a triangle, square or octagon;");
    }
}

square::square(std::istream &is) {
    is >> p1 >> p2 >> p3 >> p4;
    if(!is_figure()) {
        throw std::invalid_argument(" This figure isn't a triangle, square or octagon: ");
    }
}
double square::area() const {
    return pow(dist(p1, p2), 2);
}
point square::center() const {
    vec p1_p3 = vector(p1, p3);
    point cen = {p1.x + (p1_p3.x)/2, p1.y + (p1_p3.y)/2};
    return cen;
}

void square::print(std::ostream &out) const {
    out << "Square: [" << p1 << p2 << p3 << p4 << "]";
}

void square::sort() {
    point a[4] = {p1, p2, p3, p4};
    for(int i = 0 ;i < 3; i++) {
        for(int j = 0; j < 3; j++)
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
    }
    p1 = a[0];
    p2 = a[1];
    p3 = a[3];
    p4 = a[2];
}
bool square::is_figure() const {
    vec p1_p2 = vector(p1, p2);
    vec p2_p3 = vector(p2, p3);
    vec p3_p4 = vector(p3, p4);
    vec p4_p1 = vector(p4, p1);
    double v_mlt_1 = p1_p2.x * p2_p3.x + p1_p2.y * p2_p3.y;
    double v_mlt_2 = p2_p3.x * p3_p4.x + p2_p3.y * p3_p4.y;
    double v_mlt_3 = p3_p4.x * p4_p1.x + p3_p4.y * p4_p1.y;
    double v_mlt_4 = p4_p1.x * p1_p2.x + p4_p1.y * p1_p2.y;
    return (v_mlt_1 == 0) && (v_mlt_2 == 0) && (v_mlt_3 == 0) && (v_mlt_4 == 0);
}