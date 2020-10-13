#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include "polaire.hpp"
#include "cartesien.hpp"

template <typename TypePoint> class Nuage {
    private:
        std::vector<const TypePoint*> Vpoint;
    public:
        typedef typename std::vector<const TypePoint*>::const_iterator const_iterator;

        Nuage();
        ~Nuage();
        void ajouter(const TypePoint&);
        int size() const ;
        const_iterator begin() const;
        const_iterator end() const;
};

#endif