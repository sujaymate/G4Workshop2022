#ifndef ACTIONINIT_HH
#define ACTIONINIT_HH

#include <G4VUserActionInitialization.hh>
#include "particlegun.hh"

class ActionInit : public G4VUserActionInitialization
{
public:
  ActionInit();
  ~ActionInit();
  
  virtual void Build() const;

};
#endif