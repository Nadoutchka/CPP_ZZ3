#include "nuage.hpp"
#include <iostream>

template <typename TypePoint>
Nuage<TypePoint>::Nuage() {}

template <typename TypePoint>
Nuage<TypePoint>::~Nuage() {}

template <typename TypePoint>
void Nuage<TypePoint>::ajouter(const TypePoint& p) {
    Vpoint.push_back(&p);
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

template class Nuage<Cartesien>;
template class Nuage<Polaire>;
