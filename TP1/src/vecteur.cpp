#include "vecteur.hpp"

Vecteur::Vecteur() {
    _taille = 0;
    _capacite = 10;
    _tableau = new int[_capacite];
}

int Vecteur::operator[](int index) const {
    return _tableau[index];
}

int& Vecteur::operator[](int index) {
    return _tableau[index];
}

Vecteur& Vecteur::operator=(const Vecteur& v) {
    if (v.getCapacite() != this->getCapacite()) {
        this->setCapacite(v.getCapacite());
        delete[] _tableau;
        _tableau = new int[this->getCapacite()];
    }
    this->setTaille(v.getTaille());
    for(int i = 0; i < _taille; i++) {
        _tableau[i] = v[i];
    }
    return *this;
}

Vecteur::Vecteur(const Vecteur &v) {
    _taille = v.getTaille();
    _capacite = v.getCapacite();
    _tableau = new int[_capacite];
    for(int i = 0; i < _taille; i++) {
        _tableau[i] = v[i];
    }
}

Vecteur::Vecteur(int taille, int capacite) {
    _taille = taille;
    _capacite = capacite;
    _tableau = new int[_capacite];
}

Vecteur::~Vecteur() {}

int Vecteur::getCapacite() const {
    return _capacite;
}

int Vecteur::getTaille() const {
    return _taille;
}

void Vecteur::setCapacite(int capacite) {
    _capacite = capacite;
}

void Vecteur::setTaille(int taille) {
    _taille = taille;
}

void Vecteur::aggrandirCapa() {
    int * new_tab;
    this->setCapacite(this->getCapacite() + 10);
    new_tab = new int[this->getCapacite()];
    for(int i = 0; i < this->getTaille(); i++) {
        new_tab[i] = (*this)[i];
    }
    delete[] _tableau;
    _tableau = new_tab;
}

void Vecteur::ajouter(int elt) {
    if (getTaille() >= getCapacite()) {
        this->aggrandirCapa();
    }
    *(_tableau + getTaille()) = elt;
    this->setTaille(this->getTaille() + 1);
}

void Vecteur::supprimer(int indice) {
    this->setTaille(this->getTaille()-1);
    for(int i = indice; i < this->getTaille(); i++) {
        _tableau[i] = (*this)[i+1];
    }
}

void Vecteur::operator+(int elt) {
    this->ajouter(elt);
}

int Vecteur::operator*(Vecteur &v) const {
    int res = -1;
    if (this->getTaille() == v.getTaille()) {
        res = 0;
        for(int i = 0; i < this->getTaille(); i++) {
            res += (*this)[i] * v[i];
        }
    }
    return res;
}