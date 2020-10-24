#ifndef HISTOGRAMME_HPP
#define HISTOGRAMME_HPP

#include <set>
#include "classe.hpp"
#include "echantillon.hpp"

/* temporaire */
#include <iostream>
/*------------*/

class Histogramme {
    private :
        std::set<Classe> _classes;
    public :
        typedef std::set<Classe> classes_t;

        Histogramme();
        Histogramme(double, double, int);
        ~Histogramme();
        classes_t& getClasses();
        void ajouter(Echantillon);

};

/*----------------------IMPLEMENTATIONS----------------------*/

Histogramme::Histogramme() {}

Histogramme::Histogramme(double borneInf, double borneSup, int nbClasses) {
    double intervalle = (borneSup - borneInf) / nbClasses;
    double temp = borneInf;
    for(int i = 0; i < nbClasses; i++) {
        Classe c(temp, temp+intervalle);
        _classes.insert(c);
        temp += intervalle;
    }
}

Histogramme::~Histogramme() {}

Histogramme::classes_t& Histogramme::getClasses() {
    return _classes;
}

void Histogramme::ajouter(Echantillon e) {
    double nb;
    for(unsigned int i = 0u; i < e.getTaille(); i++) {
        nb = e.getValeur(i).getNombre();
        for(auto &it : _classes) {
            if(nb >= it.getBorneInf() && nb < it.getBorneSup()) {
                //it.ajouter();
                Classe c = it;
                c.ajouter();
                _classes.erase(it);
                _classes.insert(c);
            }            
        }
    }
}


#endif