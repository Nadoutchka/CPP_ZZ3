#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include "polaire.hpp"
#include "cartesien.hpp"

class Nuage {
    private:
        std::vector<Point*> Vpoint;
    public:
        typedef std::vector<Point*>::const_iterator const_iterator;

        Nuage();
        ~Nuage();
        void ajouter(Polaire&);
        void ajouter(Cartesien&);
        int size();
        const_iterator begin() const;
        const_iterator end() const;
};

Cartesien barycentre(Nuage&);

class BarycentreCartesien {
    public:
        Cartesien operator() (Nuage&);
};

class BarycentrePolaire {
    public:
        Polaire operator() (Nuage&);
};

#endif