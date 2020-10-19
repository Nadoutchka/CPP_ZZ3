#ifndef PUISSANCE_HPP
#define PUISSANCE_HPP

template <int N> class Puissance {
    public :
        static double valeur(double x) {
            return (Puissance<N-1>::valeur(x) * x);
            }
};

template <> class Puissance<0> {
    public :
        static double valeur(double) {
            return 1.0;
            }
};





#endif