#include <iostream>
#include "figure.h"

std::ostream& operator<< (std::ostream& os, const figure& f) {
    f.print(os);
    return os;
}