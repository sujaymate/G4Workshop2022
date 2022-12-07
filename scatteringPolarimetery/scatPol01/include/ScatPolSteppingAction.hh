
#ifndef ScatPolSteppingAction_h
#define ScatPolSteppingAction_h 1

#include "G4UserSteppingAction.hh"

class ScatPolDetectorConstruction;
class ScatPolEventAction;


class ScatPolSteppingAction : public G4UserSteppingAction
{
  public:
    ScatPolSteppingAction();
   ~ScatPolSteppingAction();

    void UserSteppingAction(const G4Step*);
    
  private:
    ScatPolDetectorConstruction* detector;
    ScatPolEventAction*          event;  
    G4SteppingManager*	   stpM;
};


#endif
