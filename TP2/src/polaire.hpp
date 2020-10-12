#ifndef POLAIRE_HPP
#define POLAIRE_HPP

#include "point.hpp"
#include "cartesien.hpp"

class Polaire : public Point {
    private:
        double _t;
        double _r;
    public:
        Polaire();
        Polaire(double, double);
        Polaire(Cartesien);
        ~Polaire();
        double getAngle() const;
        double getDistance() const;
        void setAngle(double);
        void setDistance(double);
        void afficher(std::ostream &) const;
        void convertir(Cartesien &) const;
        void convertir(Polaire &) const;
        Polaire& operator=(const Polaire*);
        
};

#endif