#ifndef ECHANTILLON_HPP
#define ECHANTILLON_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include "valeur.hpp"

class Echantillon {
    private :
        std::vector<Valeur> _valeurs;

    public :
        typedef std::vector<Valeur>::const_iterator const_iterator;
        
        Echantillon();
        ~Echantillon();
        unsigned int getTaille();
        void ajouter(double);
        Valeur getMinimum();
        Valeur getMaximum();
        Valeur getValeur(unsigned int);
};

/*----------------------IMPLEMENTATIONS----------------------*/

Echantillon::Echantillon() {}

Echantillon::~Echantillon() {}

unsigned int Echantillon::getTaille() {
    return _valeurs.size();
}

void Echantillon::ajouter(double nb) {
    Valeur v = Valeur(nb);
    _valeurs.push_back(v);
}

Valeur Echantillon::getMinimum() {
    if(this->getTaille() == 0) {
        throw std::domain_error("Erreur : Echantillon vide");
    }
    std::vector<Valeur>::iterator min = std::min_element(_valeurs.begin(), _valeurs.end());
    return *min;
}

Valeur Echantillon::getMaximum() {
    if(this->getTaille() == 0) {
        throw std::domain_error("Erreur : Echantillon vide");
    }
    std::vector<Valeur>::iterator max = std::max_element(_valeurs.begin(), _valeurs.end());
    return *max;
}

Valeur Echantillon::getValeur(unsigned int indice) {
    if(indice < 0 || indice >= this->getTaille()) {
        throw std::out_of_range("Erreur : cet element n'existe pas dans l'echantillon");
    }
    return _valeurs[indice];
}



#endif