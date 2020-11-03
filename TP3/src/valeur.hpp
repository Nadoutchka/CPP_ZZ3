#ifndef VALEUR_HPP
#define VALEUR_HPP

#include <string>

class Valeur {
    private :
        double _nb;
        std::string _etudiant;

    public :
        Valeur();
        Valeur(double);
        Valeur(double, std::string);
        ~Valeur();
        double getNombre() const;
        double getNote() const;
        std::string getEtudiant() const;
        void setNombre(double);
        void setNote(double);
        void setEtudiant(std::string);
        bool operator<(const Valeur&) const;
};
/*----------------------IMPLEMENTATIONS----------------------*/

Valeur::Valeur() : _nb(0.0), _etudiant("inconnu") {}

Valeur::Valeur(double nb) : _nb(nb), _etudiant("inconnu") {}

Valeur::Valeur(double nb, std::string etudiant) : _nb(nb), _etudiant(etudiant) {}

Valeur::~Valeur() {}

double Valeur::getNombre() const {
    return _nb;
}

double Valeur::getNote() const {
    return _nb;
}

std::string Valeur::getEtudiant() const {
    return _etudiant;
}

void Valeur::setNombre(double nb) {
    _nb = nb;
}

void Valeur::setNote(double nb) {
    _nb = nb;
}

void Valeur::setEtudiant(std::string etudiant) {
    _etudiant = etudiant;
}

bool Valeur::operator<(const Valeur& valeur) const {
    return (this->getNombre() < valeur.getNombre());
}


#endif