#include "catch.hpp"

#include "vecteur.hpp"
#include <iostream>

TEST_CASE("Vecteur::Vecteur") {
    Vecteur v = Vecteur();

    REQUIRE(v.getCapacite() == 10);
    REQUIRE(v.getTaille() == 0);  
}

TEST_CASE("Vecteur::Vecteur copie") {
    Vecteur v = Vecteur();

    for (int i=0; i<5; ++i) {
        v.ajouter(2*i);
    }

    Vecteur v2 = Vecteur(v);
    v.supprimer(3);

    REQUIRE(v2.getCapacite() == 10);
    REQUIRE(v2.getTaille() == 5);
    REQUIRE(v.getTaille() == 4);


    for (int i=0; i<5; ++i) {
        REQUIRE(v2[i] == 2*i);
    }
}

TEST_CASE("Vecteur::operator=") {
    Vecteur v = Vecteur();

    for (int i=0; i<5; ++i) {
        v.ajouter(2*i);
    }

    Vecteur v2 = v;
    v.supprimer(3);

    REQUIRE(v2.getCapacite() == 10);
    REQUIRE(v2.getTaille() == 5);
    REQUIRE(v.getTaille() == 4);


    for (int i=0; i<5; ++i) {
        REQUIRE(v2[i] == 2*i);
    }
}


TEST_CASE("Vecteur::ajouter et vecteur::operator[]") {
    Vecteur v = Vecteur();

    for (int i=0; i<5; ++i) {
        v.ajouter(2*i);
    }

    REQUIRE(v.getCapacite() == 10);
    REQUIRE(v.getTaille() == 5);

    for (int i=0; i<5; ++i) {
        REQUIRE(v[i] == 2*i);
    }
}

TEST_CASE("Vecteur::ajouter avec dépassement") {
    Vecteur v = Vecteur();

    for (int i=0; i<15; ++i) {
        v.ajouter(2*i);
    }

    REQUIRE(v.getCapacite() == 20);
    REQUIRE(v.getTaille() == 15);

    for (int i=0; i<15; ++i) {
        REQUIRE(v[i] == 2*i);
    }
}

TEST_CASE("Vecteur::supprimer") {
    Vecteur v = Vecteur();

    for (int i=0; i<5; ++i) {
        v.ajouter(2*i);
    }

    REQUIRE(v.getCapacite() == 10);
    REQUIRE(v.getTaille() == 5);

    v.supprimer(0);

    REQUIRE(v.getCapacite() == 10);
    REQUIRE(v.getTaille() == 4);

    for (int i=0; i<4; ++i) {
        REQUIRE(v[i] == 2*(i+1));
    }

    v.supprimer(v.getTaille()-1);

    REQUIRE(v.getCapacite() == 10);
    REQUIRE(v.getTaille() == 3);
    
    for (int i=0; i<3; ++i) {
        REQUIRE(v[i] == 2*(i+1));
    }
}

TEST_CASE("Vecteur::operator+") {
    Vecteur v = Vecteur();

    for (int i=0; i<5; ++i) {
        v + 2*i;
    }

    REQUIRE(v.getCapacite() == 10);
    REQUIRE(v.getTaille() == 5);

    for (int i=0; i<5; ++i) {
        REQUIRE(v[i] == 2*i);
    }
}

TEST_CASE("Vecteur::operator[] en ecriture") {
    Vecteur v = Vecteur();

    for (int i=0; i<5; ++i) {
        v + 2*i;
    }

    for (int i=0; i<5; ++i) {
        v[i] = 0;
    }

    for (int i=0; i<5; ++i) {
        REQUIRE(v[i] == 0);
    }

}


TEST_CASE("Vecteur::operator*") {
    Vecteur v1 = Vecteur();

    v1.ajouter(0);
    v1.ajouter(1);
    v1.ajouter(2);

    Vecteur v2 = v1;

    REQUIRE(v1*v2 == 5);
}

TEST_CASE("Vector::Iterateur") {
    Vecteur v = Vecteur();

    v.ajouter(0);
    v.ajouter(1);
    v.ajouter(2);

    Vecteur::Iterateur it = v.begin();

    int i=0;

    for (it=v.begin(); it!=v.end(); ++it) {
        std::cout << *it << std::endl;
        REQUIRE(*it == i);
        ++i;
    }
}

bool Vecteur::Iterateur::operator!=(Vecteur::Iterateur it) {
    return (this->getVecteur() != it.getVecteur()) || (this->getIndex() != it.getIndex());
}