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
        class Iterateur {
            private :
                Vecteur * _vecteur;
                int _index;
            public :
                Iterateur();
                ~Iterateur();
                Vecteur * getVecteur();
                void setVecteur(Vecteur&);
                int getIndex();
                void setIndex(int);
                int operator*();
                Iterateur& operator++();
                //Iterateur operator++(int);
                bool operator!=(Iterateur);

        };
        Vecteur::Iterateur begin();
        Vecteur::Iterateur end();
};


#endif