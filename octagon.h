#ifndef LAB3_OCTAGON_H
#define LAB3_OCTAGON_H
#include"figure.h"

class octagon : public figure {
public:
    octagon() = default;

    octagon(const point &p1_, const point &p2_,
            const point &p3_, const point &p4_,
            const point &p5_, const point &p6_,
            const point &p7_, const point &p8_);

    octagon(std::istream &is);

    point center() const override;

    double area() const override;

    void print(std::ostream &os) const override;

    bool is_figure() const override;

private:
    point p1{};
    point p2{};
    point p3{};
    point p4{};
    point p5{};
    point p6{};
    point p7{};
    point p8{};

};





#endif //LAB3_OCTAGON_H
