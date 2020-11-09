#ifndef HISTOGRAMME_HPP
#define HISTOGRAMME_HPP

#include <set>
#include <map>
#include <sstream>
#include "classe.hpp"
#include "echantillon.hpp"
#include "comparateur_quantite.hpp"

/* temporaire */
#include <iostream>
/*------------*/

template <typename Comparateur = std::less<Classe>>
class Histogramme {
    private :
        std::set<Classe, Comparateur> _classes;
        std::multimap<Classe, Valeur> _valeurs;
    public :
        typedef std::set<Classe, Comparateur> classes_t;
        typedef std::multimap<Classe, Valeur> valeurs_t;
        typedef std::multimap<Classe, Valeur>::const_iterator it_valeurs_t;
        typedef std::pair<it_valeurs_t, it_valeurs_t> interval_t;

        Histogramme();
        template <typename Comparateur2>
        Histogramme(const Histogramme<Comparateur2>&);
        Histogramme(double, double, int);
        ~Histogramme();
        const classes_t& getClasses() const;
        const valeurs_t& getValeurs() const;
        const interval_t getValeurs(const Classe&) const;
        void ajouter(Echantillon);
        void ajouter(double);
};

template <typename Comparateur>
std::ostream& operator<<(std::ostream&, const Histogramme<Comparateur>&);

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
template <typename Comparateur2>
Histogramme<Comparateur>::Histogramme(const Histogramme<Comparateur2> &h) {
    for(auto &it : h.getClasses()) {
        _classes.insert(it);
    }
    for(auto &it : h.getValeurs()) {
        _valeurs.insert(it);
    }
}

template <typename Comparateur>
Histogramme<Comparateur>::~Histogramme() {}

template <typename Comparateur>
const typename Histogramme<Comparateur>::classes_t& Histogramme<Comparateur>::getClasses() const{
    return _classes;
}

template <typename Comparateur>
const typename Histogramme<Comparateur>::valeurs_t& Histogramme<Comparateur>::getValeurs() const{
    return _valeurs;
}

template <typename Comparateur>
const typename Histogramme<Comparateur>::interval_t Histogramme<Comparateur>::getValeurs(const Classe& c) const{
    return getValeurs().equal_range(c);
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
                _valeurs.insert(std::pair<Classe,Valeur>(c, e.getValeur(i)));
            }            
        }
    }
    std::cout << (*this);
}

template <typename Comparateur>
void Histogramme<Comparateur>::ajouter(double nb) {
    Echantillon e;
    e.ajouter(nb);
    this->ajouter(e);
}

template <typename Comparateur>
std::ostream& operator<<(std::ostream& os, const Histogramme<Comparateur> &h)
{
    for (auto &itc : h.getClasses()) {
        os << "Classe : " << itc.getBorneInf() << " -> " << itc.getBorneSup() << std::endl;
        os << "\tEtudiants - Notes :" << std::endl;
        for (auto itv = h.getValeurs(itc).first; itv != h.getValeurs(itc).second; itv++) {
            if (h.getValeurs(itc).first == h.getValeurs(itc).second) {
                os << "\t\tAucun etudiant" << std::endl;
            } else {
                os << "\t\t" << itv->second.getEtudiant() << " - " << itv->second.getNote() << std::endl;
            }
        }
    }
    return os;
}


#endif