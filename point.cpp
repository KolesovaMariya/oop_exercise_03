#include "point.h"

std::ostream  &operator<< (std::ostream &out, point const &a) {
    out << "(" << a.x << "," << a.y << ")";
    return out;
}

std::istream &operator>>(std::istream &in, point &a) {
    in >> a.x >> a.y;
    return in;
}
bool operator>(point a, point b) {
    if (a.x > b.x) {
        return true;
    } else if ( a.x == b.x) {
        return a.y > b.y;
    } else {
        return false;
    }
}

void swap(point &a, point &b) {
    point tmp = a;
    a = b;
    b = tmp;
}

bool operator==(point a, point b) {
    return((a.x == b.x) && (a.y == b.y));
}

double dist(point a, point b) {
    return sqrt(pow((a.x - b.x),2) + pow((a.y - b.y),2));
}
vec vector(point a, point b) {
    vec v{};
    v.x = b.x - a.x;
    v.y = b.y - a.y;
    return v;
}

bool same_line(point a, point b, point c) {
    vec ab = vector(a, b);
    vec bc = vector(b, c);
    return ((ab.x) / (bc.x) != (ab.y) / (bc.y));
}
