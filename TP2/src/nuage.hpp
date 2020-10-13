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

#endif