// Entetes //---------------------------------------------------------------------------------------
#include <algorithm>
#include <deque>
#include <functional>
#include "vecteur03.hpp"

// Fonction principale //---------------------------------------------------------------------------
int main(void) {
 Vecteur v1;
 Vecteur v2;

 complexe_t::stats();

 //for (unsigned i = 0; i<v1.getTaille(); ++i) v1[i]=complexe_t(10*i,i*i);
 //for (unsigned i = 0; i<v2.getTaille(); ++i) v2[i]=complexe_t(i,i+1);

 unsigned int i = 0;
 for (auto & it : v1) {
     it=complexe_t(10*i,i*i);
     i++;
 }

 unsigned int j = 0;
 for (auto & it : v2) {
     it=complexe_t(j,j+1);
     j++;
 }

 std::cout << std::endl << "v1 = " << v1 << std::endl;
 std::cout << "v2 = " << v2 << std::endl;
 complexe_t::stats();

 Vecteur v3 = v1;

 std::cout << std::endl << "v3 = " << v3 << std::endl;
 complexe_t::stats();

 Vecteur v4;

 v4=v1+v2;

 std::cout << std::endl << "v4 = " << v4 << std::endl;
 complexe_t::stats();

 Vecteur v5;

 v5=v1*v2;

 std::cout << std::endl << "v5 = " << v5 << std::endl;
 complexe_t::stats();

 std::deque<complexe_t> liste;

 //for (unsigned i = 0; i<v5.getTaille(); ++i) liste.push_back(v5[i]);

 for (auto & it : v5) liste.push_back(it);

 std::cout << std::endl << "liste = v5" << std::endl;
 complexe_t::stats();

 //std::sort(liste.begin(),liste.end(),ComparateurComplexe());

 std::sort(liste.begin(),liste.end(), [] (complexe_t a,complexe_t b) {
     return a.reel<b.reel || (a.reel==b.reel && a.imaginaire<b.imaginaire);
    });
    
 std::cout << std::endl;
 //for (unsigned i = 0; i<liste.size(); ++i) std::cout << liste[i] << " ";
 
 for (auto & it : liste) std::cout << it << " ";

 std::cout << std::endl;
 complexe_t::stats();


 std::cout << std::endl << "Tests question 5 : fonction generique comme operateur" << v5 << std::endl;
 std::cout << "v6 = v1 + v2" << std::endl;
 Vecteur v6 = operateurBinaire([] (const complexe_t &a, const complexe_t &b) {return a+b;}, v1, v2);
 std::cout << "v6 = " << v6 << std::endl;
 std::cout << "v7 = v4 - v1" << std::endl;
 Vecteur v7 = operateurBinaire(Soustraction(), v4, v1);
 std::cout << "v7 = " << v7 << std::endl;
 std::cout << "v8 = v1 * v2" << std::endl;
 Vecteur v8 = operateurBinaire(multiplication, v1, v2);
 std::cout << "v8 = " << v8 << std::endl;
}


// Fin //-------------------------------------------------------------------------------------------
