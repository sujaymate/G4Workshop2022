#ifndef ScatPolEventAction_h
#define ScatPolEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"
#include "ScatPolRunAction.hh"

class ScatPolRunAction;


class ScatPolEventAction : public G4UserEventAction
{
 public:
   ScatPolEventAction();
  ~ScatPolEventAction();

 public:
   void  BeginOfEventAction(const G4Event*);
   void  EndOfEventAction(const G4Event*);
    
    
 private:
   ScatPolRunAction*  runAct;
};


#endif

    
