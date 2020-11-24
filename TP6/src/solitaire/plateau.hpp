// Gardien //---------------------------------------------------------------------------------------
#ifndef _PLATEAU_HPP_
#define _PLATEAU_HPP_

#include <vector>
#include "carte.hpp"

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
        const Carte * getSommet() const { return *(_colonne.end()); }
        Carte * getCarte(int pos) const { return _colonne[pos]; }
 //-----------------------------------------------------------------------------------------Methodes
        bool estVide() const { return _colonne.empty(); }
        void ajouter(Carte* carte) { _colonne.push_back(carte); }
        void ajouter(Main& m) { for (auto &it: m) ajouter(it); }
        void retirer(int pos, Main& m);
};

// Classe  D o c k //-------------------------------------------------------------------------------
class Dock {
 //----------------------------------------------------------------------------------------Attributs
    private :
        std::vector<Carte*> _dock;
 //---------------------------------------------------------------------------------------Accesseurs
    public:
        Carte * getSommet() const { return *(_dock.end()); }
 //-----------------------------------------------------------------------------------------Methodes
        bool estVide() const { return _dock.empty(); }
        void ajouter(Carte * carte) { _dock.push_back(carte); }
        Carte * retirer() {
            Carte * carte = getSommet();
            _dock.erase(_dock.end());
            return carte;
        }
};

// Classe  P i o c h e //---------------------------------------------------------------------------
class Pioche {
 //----------------------------------------------------------------------------------------Attributs
    private :
        std::vector<Carte*> _pioche;
 //---------------------------------------------------------------------------------------Accesseurs
    public:
        Carte * getProchaine() const;
        Carte * getVisible() const;
 //-----------------------------------------------------------------------------------------Methodes
        bool rienRetourne();
        bool toutRetourne();
        bool estVide() const;
        void ajouter(Carte*);
        bool tirer(Carte*);
        Carte * retirer();
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
