#include "point.hpp"

Point::Point() {}

Point::~Point() {}

std::ostream& operator<< (std::ostream &ss, const Point &p) {
    p.afficher(ss);
    return ss;
}

