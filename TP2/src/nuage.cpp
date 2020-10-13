#include "nuage.hpp"
#include <iostream>

template <typename TypePoint>
Nuage<TypePoint>::Nuage() {}

template <typename TypePoint>
Nuage<TypePoint>::~Nuage() {}

template <typename TypePoint>
void Nuage<TypePoint>::ajouter(TypePoint p) {
    Vpoint.push_back(p);
}

template <typename TypePoint>
int Nuage<TypePoint>::size() const {
    return Vpoint.size();
}

template <typename TypePoint>
typename Nuage<TypePoint>::const_iterator Nuage<TypePoint>::begin() const {
    return Vpoint.begin();
}

template <typename TypePoint>
typename Nuage<TypePoint>::const_iterator Nuage<TypePoint>::end() const {
    return Vpoint.end();
}

template <typename TypePoint>
TypePoint barycentre_v1(Nuage<TypePoint> &n) {
    double somme_x = 0;
    double somme_y = 0;
    int size = n.size();
    TypePoint bar = TypePoint();
    if(size > 0) {
        Cartesien c;
        typename Nuage<TypePoint>::const_iterator it;
        for (it = n.begin(); it < n.end(); it++) {
            it->convertir(c);
            somme_x += c.getX();
            somme_y += c.getY();
        }
        c.setX(somme_x/size);
        c.setY(somme_y/size);
        c.convertir(bar);
    }
    return bar;
}

template class Nuage<Cartesien>;
template class Nuage<Polaire>;

template Cartesien barycentre_v1(Nuage<Cartesien>&);
template Polaire barycentre_v1(Nuage<Polaire>&);