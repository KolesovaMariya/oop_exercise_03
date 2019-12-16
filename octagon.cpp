#include "octagon.h"
#include "triangle.h"

octagon::octagon (const point &p1_, const point &p2_,
                  const point &p3_, const point &p4_,
                  const point &p5_, const point &p6_,
                  const point &p7_, const point &p8_):
                  p1(p1_), p2(p2_), p3(p3_), p4(p4_),
                  p5(p5_), p6(p6_), p7(p7_), p8(p8_) {}

octagon::octagon(std::istream &is) {
    is >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7 >> p8;
}

point octagon::center() const {
    point cent{};
    cent.x = (p1.x + p2.x + p3.x + p4.x + p5.x + p6.x + p7.x + p8.x)/8;
    cent.y = (p1.y + p2.y + p3.y + p4.y + p5.y + p6.y + p7.y + p8.y)/8;
    return cent;
}

double octagon::area() const {
    point cent = this->center();
    point m[8] = {p1, p2 ,p3, p4, p5, p6, p7, p8};
    double ar = 0;
    for(int i = 0; i < 7; i++) {
        triangle a{m[i], m[i+1], cent};
        ar += a.area();
    }
    triangle a{p8, p1, cent};
    ar += a.area();
    return ar;
}

void octagon::print(std::ostream &os) const {
    os << "Octagon [" << p1 << ", "<< p2 << ", "<< p3 << ", "<< p4 << ", "<<
    p5 << ", "<< p6 << ", "<< p7 << ", "<< p8 << "]";
}
bool octagon::is_figure() const {
    bool flag = true;
    point a[8] = {p1, p2, p3, p4, p5, p6, p7, p8};
    for(int i = 0; i < 7; i++) {
        if(a[i] == a[i+1]) {
            flag = false;
            break;
        }
    }
    if (flag) return true;
    for(int i = 0; i < 7; i++) {
        if(!(a[i] == a[i+1])) {
            return false;
        }
    }
    return true;
}