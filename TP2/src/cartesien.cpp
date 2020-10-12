#include "cartesien.hpp"

Cartesien::Cartesien(): _x(0), _y(0) {}

Cartesien::~Cartesien() {}

Cartesien::Cartesien(double x, double y): _x(x), _y(y) {}

Cartesien::Cartesien(Polaire p) {
    Cartesien c;
    p.convertir(c);
    _x = c.getX();
    _y = c.getY();
}

double Cartesien::getX() const {
    return _x;
}

double Cartesien::getY() const {
    return _y;
}

void Cartesien::setX(double x) {
    _x = x;
}

void Cartesien::setY(double y) {
    _y = y;
}

void Cartesien::afficher(std::ostream & ss) const {
    ss << "(x=" << this->getX() << ";y=" << this->getY() << ")";
}

void Cartesien::convertir(Cartesien &c) const {
    c.setX(this->getX());
    c.setY(this->getY());
}

void Cartesien::convertir(Polaire &p) const {
    p.setDistance(hypot(this->getX(), this->getY()));
    p.setAngle(atan2(this->getY(), this->getX()) * 180 / pi);
}