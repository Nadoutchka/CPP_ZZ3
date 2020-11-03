#ifndef CLASSE_HPP
#define CLASSE_HPP

class Classe {
    private :
        double _borneInf;
        double _borneSup;
        unsigned int _quantite;

    public :
        Classe();
        Classe(double, double);
        ~Classe();
        double getBorneInf() const;
        void setBorneInf(double);
        double getBorneSup() const;
        void setBorneSup(double);
        double getQuantite() const;
        void setQuantite(double);
        void ajouter();
        bool operator<(const Classe&) const;
        bool operator>(const Classe&) const;
};

/*----------------------IMPLEMENTATIONS----------------------*/

Classe::Classe() : _borneInf(0.0), _borneSup(0.0), _quantite(0u) {}

Classe::Classe(double borneInf, double borneSup) : _borneInf(borneInf), _borneSup(borneSup), _quantite(0u) {}

Classe::~Classe() {}

double Classe::getBorneInf() const {
    return _borneInf;
}

void Classe::setBorneInf(double borneInf) {
    _borneInf = borneInf;
}

double Classe::getBorneSup() const {
    return _borneSup;
}

void Classe::setBorneSup(double borneSup) {
    _borneSup = borneSup;
}

double Classe::getQuantite() const {
    return _quantite;
}

void Classe::setQuantite(double quantite) {
    _quantite = quantite;
}

void Classe::ajouter() {
    _quantite++;
}

bool Classe::operator<(const Classe& classe) const {
    return this->getBorneInf() < classe.getBorneInf();
}

bool Classe::operator>(const Classe& classe) const {
    return this->getBorneInf() > classe.getBorneInf();
}

#endif