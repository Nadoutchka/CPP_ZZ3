// Entetes //---------------------------------------------------------------------------------------
#include <solitaire/paquet.hpp>

// Implementation  P a q u e t //-------------------------------------------------------------------

//--------------------------------------------------------------------------------------Constructeur
Paquet::Paquet(void) : cartes_(), courante_(0) {
 for (int f=0; f<4; f++)
  for (int v=0; v<13; v++) cartes_.push_back(new Carte(f,v));
}

//---------------------------------------------------------------------------------------Destructeur
Paquet::~Paquet(void)
{ for (size_t i=0; i<cartes_.size(); ++i) delete cartes_[i]; }

// Fin //-------------------------------------------------------------------------------------------
