#ifndef CARTESIEN_HPP
#define CARTESIEN_HPP

#include "point.hpp"
#include "polaire.hpp"

class Cartesien : public Point {
    private:
        double _x;
        double _y;
    public:
        Cartesien();
        Cartesien(double, double);
        Cartesien(Polaire);
        ~Cartesien();
        double getX() const;
        double getY() const;
        void setX(double);
        void setY(double);
        void afficher(std::ostream &) const;
        void convertir(Cartesien &) const;
        void convertir(Polaire &) const;
};

#endif