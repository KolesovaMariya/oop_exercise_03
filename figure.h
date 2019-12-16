#ifndef LAB3_FIGURE_H
#define LAB3_FIGURE_H

#include "point.h"
#include<iostream>

class figure {
public:
    virtual point center()  const = 0;
    virtual double area() const = 0;
    virtual void print(std::ostream&) const = 0;

    virtual bool is_figure() const = 0;
    virtual ~figure() = default;
};



#endif //LAB3_FIGURE_H
