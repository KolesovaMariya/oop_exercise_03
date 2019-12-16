#ifndef LAB3_POINT_H
#define LAB3_POINT_H

#include <iostream>
#include <cmath>


struct point {
    double x;
    double y;
};



std::ostream &operator<<(std::ostream &out, point const &a);

std::istream &operator>>(std::istream &in, point &a);
bool operator==(point a, point b);
bool operator>(point a, point b);
void swap(point &a, point &b);
double dist(point a, point b);


struct vec {
    double x;
    double y;
};
vec vector(point a, point b);
bool same_line(point a, point b, point c);


#endif //LAB3_POINT_H
