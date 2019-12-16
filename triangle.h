#ifndef LAB3_TRIANGLE_H
#define LAB3_TRIANGLE_H

#include"figure.h"

class triangle : public figure {
public:
    triangle() = default;

    triangle(const point &a, const point &b, const point &c);

    triangle(std::istream &is);

    point center() const override;

    double area() const override;

    void print(std::ostream &os) const override;
    bool is_figure() const;

private:
    point p1{};
    point p2{};
    point p3{};

};
#endif //LAB{}3_TRIANGLE_H
