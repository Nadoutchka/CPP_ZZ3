# include "polaire.hpp"

Polaire::Polaire(): _t(0), _r(0) {}

Polaire::~Polaire() {}

Polaire::Polaire(double t, double r): _t(t), _r(r) {}

Polaire::Polaire(Cartesien c) {
    Polaire p;
    c.convertir(p);
    _r = p.getDistance();
    _t = p.getAngle();
}

double Polaire::getDistance() const {
    return _r;
}

double Polaire::getAngle() const {
    return _t;
}

void Polaire::setDistance(double r) {
    _r = r;
}

void Polaire::setAngle(double t) {
    _t = t;
}

void Polaire::afficher(std::ostream & ss) const {
    ss << "(a=" << this->getAngle() << ";d=" << this->getDistance() << ")";
}

void Polaire::convertir(Cartesien &c) const {
    c.setX(this->getDistance() * (cos(this->getAngle() * pi / 180)));
    c.setY(this->getDistance() * (sin(this->getAngle() * pi / 180)));
}

void Polaire::convertir(Polaire &p) const {
    p.setDistance(this->getDistance());
    p.setAngle(this->getAngle());
}