#ifndef STEPPINGACTION_HH
#define STEPPINGACTION_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"

#include "hgcaldetector.hh"
#include "eventaction.hh"

class SteppingAction : public G4UserSteppingAction
{
public:
    SteppingAction(EventAction* eventAction);
    ~SteppingAction();
    
    virtual void UserSteppingAction(const G4Step*);
    
private:
    EventAction *fEventAction;
};

#endif
