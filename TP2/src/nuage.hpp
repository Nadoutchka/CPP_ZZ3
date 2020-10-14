#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include "polaire.hpp"
#include "cartesien.hpp"

template <typename TypePoint> class Nuage {
    private:
        std::vector<TypePoint> Vpoint;
    public:
        typedef typename std::vector<TypePoint>::const_iterator const_iterator;

        Nuage();
        ~Nuage();
        void ajouter(TypePoint);
        int size() const ;
        const_iterator begin() const;
        const_iterator end() const;
};

template <typename TypePoint>
TypePoint barycentre_v1(Nuage<TypePoint>&);

template <typename TypePoint, template <typename> class Conteneur>
TypePoint barycentre_v2(Conteneur<TypePoint>&);

template <typename TypePoint, template <typename, typename = std::allocator<TypePoint>> class Conteneur>
TypePoint barycentre_v2(Conteneur<TypePoint>&);



/*----------------------IMPLEMENTATIONS----------------------*/

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

/* Specialisation pour test 4b  */
//template <>
//Polaire barycentre_v1<Polaire>(Nuage<Polaire> &n) {
//    double somme_t = 0;
//    double somme_r = 0;
//    int size = n.size();
//    Polaire bar = Polaire();
//    if(size > 0) {
//        Nuage<Polaire>::const_iterator it;
//        for (it = n.begin(); it < n.end(); it++) {
//            somme_t += it->getAngle();
//            somme_r += it->getDistance();
//        }
//        bar.setAngle(somme_t/size);
//        bar.setDistance(somme_r/size);
//    }
//    return bar;
//}

template <typename TypePoint, template <typename> class Conteneur>
TypePoint barycentre_v2(Conteneur<TypePoint> &n) {
    double somme_x = 0;
    double somme_y = 0;
    int size = n.size();
    TypePoint bar = TypePoint();
    if(size > 0) {
        Cartesien c;
        typename Conteneur<TypePoint>::const_iterator it;
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

template <typename TypePoint, template <typename, typename = std::allocator<TypePoint>> class Conteneur>
TypePoint barycentre_v2(Conteneur<TypePoint> &n) {
    double somme_x = 0;
    double somme_y = 0;
    int size = n.size();
    TypePoint bar = TypePoint();
    if(size > 0) {
        Cartesien c;
        typename Conteneur<TypePoint>::const_iterator it;
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


#endif