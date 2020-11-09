#ifndef COMP_QTE_HPP
#define COMP_QTE_HPP

#include "classe.hpp"


template <typename C>
class ComparateurQuantite {
    public:
        bool operator () (const C &a, const C & b) const {
            return (a.getQuantite() != b.getQuantite() ? a.getQuantite() > b.getQuantite() : a < b);
            }
};

#endif