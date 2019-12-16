#ifndef LAB3_SQUARE_H
#define LAB3_SQUARE_H

#include "figure.h"

class square : public figure {
public:
    square() = default;
    square(point p1_, point p2_, point p3_, point p4_);
    square(std::istream &in);
    double area() const override;
    point center() const override;
    void print(std::ostream&) const override ;
    bool is_figure() const override;
    void sort();
private:
     point p1{}, p2{}, p3{}, p4{};
};


#endif //LAB3_SQUARE_H
