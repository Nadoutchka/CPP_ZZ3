#ifndef HISTOGRAMME_HPP
#define HISTOGRAMME_HPP

#include <set>
#include "classe.hpp"
#include "echantillon.hpp"

/* temporaire */
#include <iostream>
/*------------*/

template <typename Comparateur = std::less<Classe>>
class Histogramme {
    private :
        std::set<Classe, Comparateur> _classes;
    public :
        typedef std::set<Classe, Comparateur> classes_t;

        Histogramme();
        Histogramme(double, double, int);
        ~Histogramme();
        classes_t& getClasses();
        void ajouter(Echantillon);
        void ajouter(double);

};

template <typename C>
class ComparateurQuantite {
    public:
        bool operator () (const C &a, const C & b) const {
            return (a < b);
            }
};

/*----------------------IMPLEMENTATIONS----------------------*/

template <typename Comparateur>
Histogramme<Comparateur>::Histogramme() {}

template <typename Comparateur>
Histogramme<Comparateur>::Histogramme(double borneInf, double borneSup, int nbClasses) {
    double intervalle = (borneSup - borneInf) / nbClasses;
    double temp = borneInf;
    for(int i = 0; i < nbClasses; i++) {
        Classe c(temp, temp+intervalle);
        _classes.insert(c);
        temp += intervalle;
    }
}

template <typename Comparateur>
Histogramme<Comparateur>::~Histogramme() {}

template <typename Comparateur>
typename Histogramme<Comparateur>::classes_t& Histogramme<Comparateur>::getClasses() {
    return _classes;
}

template <typename Comparateur>
void Histogramme<Comparateur>::ajouter(Echantillon e) {
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

template <typename Comparateur>
void Histogramme<Comparateur>::ajouter(double nb) {
    Echantillon e;
    e.ajouter(nb);
    this->ajouter(e);
}


#endif