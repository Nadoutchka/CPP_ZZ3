#ifndef VECTEUR_HPP
#define VECTEUR_HPP


class Vecteur {
    private :
        int * _tableau;
        int _capacite;
        int _taille;
    public :
        Vecteur();
        Vecteur(const Vecteur&);
        Vecteur(int, int);
        ~Vecteur();
        int operator[](int) const;
        int& operator[](int);
        Vecteur& operator=(const Vecteur&);
        int getCapacite() const;
        int getTaille() const;
        void setCapacite(int);
        void setTaille(int);
        void aggrandirCapa();
        void ajouter(int);
        void supprimer(int);
        void operator+(int);
        int operator*(Vecteur&) const;
};


#endif