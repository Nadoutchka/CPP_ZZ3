#include "nuage.hpp"

Nuage::Nuage() {}

Nuage::~Nuage() {}

void Nuage::ajouter(Polaire &p) {
    Vpoint.push_back(&p);
}

void Nuage::ajouter(Cartesien &c) {
    Vpoint.push_back(&c);
}

int Nuage::size() {
    return Vpoint.size();
}

Nuage::const_iterator Nuage::begin() const {
    return Vpoint.begin();
}

Nuage::const_iterator Nuage::end() const {
    return Vpoint.end();
}

Cartesien barycentre(Nuage &n) {
    double somme_x = 0;
    double somme_y = 0;
    int size = n.size();
    Cartesien c;
    Nuage::const_iterator it;
    for (it = n.begin(); it < n.end(); it++) {
        (*it)->convertir(c);
        somme_x += c.getX();
        somme_y += c.getY();
    }
    Cartesien bar = Cartesien(somme_x/size, somme_y/size);
    return bar;
}

Cartesien BarycentreCartesien::operator() (Nuage &n) {
    return barycentre(n);
}

Polaire BarycentrePolaire::operator() (Nuage &n) {
    Polaire p;
    barycentre(n).convertir(p);
    return p;
}
