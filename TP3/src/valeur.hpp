#ifndef VALEUR_HPP
#define VALEUR_HPP

class Valeur {
    private :
        double _nb;

    public :
        Valeur();
        Valeur(double);
        ~Valeur();
        double getNombre() const;
        void setNombre(double);
        bool operator<(const Valeur&) const;
};
/*----------------------IMPLEMENTATIONS----------------------*/

Valeur::Valeur() : _nb(0.0) {}

Valeur::Valeur(double nb) : _nb(nb) {}

Valeur::~Valeur() {}

double Valeur::getNombre() const {
    return _nb;
}

void Valeur::setNombre(double nb) {
    _nb = nb;
}

bool Valeur::operator<(const Valeur& valeur) const {
    return (this->getNombre() < valeur.getNombre());
}


#endif