// Gardien //---------------------------------------------------------------------------------------
#ifndef _PLATEAU_HPP_
#define _PLATEAU_HPP_

#include <vector>
#include "carte.hpp"

// Pioche::rienRetourné     retourne vrai si la pioche est pleine et que la défausse est vide.
// Pioche::toutRetourné     retourne vrai si la pioche est vide et la défausse est pleine.
// Pioche::getVisible       retourne la carte au sommet de la défausse (la dernière qui a été piochée).
// Pioche::tirer            déplace la carte au sommet de la pioche vers la défausse, puis retourne vrai si la pioche n'était pas vide.
// Pioche::retirer          retire la carte au sommet de la défausse (pop) et retourne cette carte.
// Pioche::ajouter          insère une carte face cachée dans la pioche.
// Colonne::getCarte(i)     retourne la i-ème carte visible d'une colonne.
// Colonne::ajouter         permettent de déplacer plusieurs cartes d'une colonne à une autre par l'intermédiaire de Main.
// Colonne::retirer         permettent de déplacer plusieurs cartes d'une colonne à une autre par l'intermédiaire de Main.

// Classe  M a i n //-------------------------------------------------------------------------------
class Main {
 //----------------------------------------------------------------------------------------Attributs
    public :
        std::vector<Carte*> main;
 //---------------------------------------------------------------------------------------Iterateurs
    public :
        typedef std::vector<Carte*>::const_iterator const_iterator;
        const_iterator begin() { return main.begin(); }
        const_iterator end() { return main.end(); }

};

// Classe  C o l o n n e //-------------------------------------------------------------------------
class Colonne {
 //----------------------------------------------------------------------------------------Attributs
    private :
        std::vector<Carte*> _colonne;
 //---------------------------------------------------------------------------------------Accesseurs
    public:
        int getTaille() const { return _colonne.size(); }
        const Carte * getSommet() const { return _colonne.back(); }
        Carte * getCarte(int pos) const { return _colonne[pos]; }
 //-----------------------------------------------------------------------------------------Methodes
        bool estVide() const { return _colonne.empty(); }
        void ajouter(Carte* carte) { _colonne.push_back(carte); }
        void ajouter(Main& m) { for (auto &it: m) ajouter(it); }
        void retirer(int pos, Main& m) {
            for (auto it = _colonne.begin() + pos; it != _colonne.end(); it++) {
                m.main.push_back(*it);
            }
            _colonne.erase(_colonne.begin() + pos, _colonne.end());
        }
};

// Classe  D o c k //-------------------------------------------------------------------------------
class Dock {
 //----------------------------------------------------------------------------------------Attributs
    private :
        std::vector<Carte*> _dock;
 //---------------------------------------------------------------------------------------Accesseurs
    public:
        Carte * getSommet() const { return _dock.back(); }
 //-----------------------------------------------------------------------------------------Methodes
        bool estVide() const { return _dock.empty(); }
        void ajouter(Carte * carte) { _dock.push_back(carte); }
        Carte * retirer() {
            Carte * carte = getSommet();
            _dock.pop_back();
            return carte;
        }
};

// Classe  P i o c h e //---------------------------------------------------------------------------
class Pioche {
 //----------------------------------------------------------------------------------------Attributs
    private :
        std::vector<Carte*> _pioche;
        std::vector<Carte*> _defausse;
 //---------------------------------------------------------------------------------------Accesseurs
    public:
        Carte * getProchaine() const { return _pioche.back(); };
        Carte * getVisible() const { return _defausse.back(); };
 //-----------------------------------------------------------------------------------------Methodes
        bool rienRetourne() { return !(_pioche.empty()) && _defausse.empty(); };
        bool toutRetourne() { return !(_defausse.empty()) && _pioche.empty(); };
        bool estVide() const { return _pioche.empty(); };
        void ajouter(Carte * carte) { _pioche.push_back(carte); };
        bool tirer() {
            if (!estVide()) {
                Carte * carte = _pioche.back();
                _pioche.pop_back();
                _defausse.push_back(carte);
            }
            return !estVide();
        };
        Carte * retirer() {
            Carte * carte = _defausse.back();
            _defausse.pop_back();
            return carte;
        };
};


// Classe  P l a t e a u //-------------------------------------------------------------------------
class Plateau {
 //----------------------------------------------------------------------------------------Attributs
 // protected: Colonne colonnes_[7];
 // protected: Dock    docks_[4];
 // protected: Pioche  pioche_;
 // protected: Main    main_;
 //---------------------------------------------------------------------------------------Accesseurs
 // public: Colonne & getColonne(size_t indice) { return colonnes_[indice]; }
 // public: Dock &    getDock(size_t indice) { return docks_[indice]; }
 // public: Pioche &  getPioche(void) { return pioche_; }
 // public: Main &    getMain(void) { return main_; }
 //
 // public: const Colonne & getColonne(size_t indice) const { return colonnes_[indice]; }
 // public: const Dock &    getDock(size_t indice) const { return docks_[indice]; }
 // public: const Pioche &  getPioche(void) const { return pioche_; }
 // public: const Main &    getMain(void) const { return main_; }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
