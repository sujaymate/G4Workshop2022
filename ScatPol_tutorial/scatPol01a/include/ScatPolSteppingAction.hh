
#ifndef ScatPolSteppingAction_h
#define ScatPolSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "g4root.hh"

class ScatPolDetectorConstruction;

class ScatPolSteppingAction : public G4UserSteppingAction
{
  public:
    ScatPolSteppingAction();
   ~ScatPolSteppingAction();

    void UserSteppingAction(const G4Step*);
    
  private:
    ScatPolDetectorConstruction* detector;
    G4SteppingManager*	   stpM;
};


#endif
