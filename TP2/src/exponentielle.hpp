#ifndef EXPONENTIELLE_HPP
#define EXPONENTIELLE_HPP

#include <factorielle.hpp>
#include <puissance.hpp>


template <int N> class Exponentielle {
    public :
        static double valeur(double x) {
            return (Exponentielle<N-1>::valeur(x) + Puissance<N>::valeur(x) / Factorielle<N>::valeur);
            }
};

template <> struct Exponentielle<0> {
    public :
        static double valeur(double) {
            return 1.0;
            }
};

#endif