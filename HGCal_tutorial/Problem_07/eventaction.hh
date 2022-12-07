#ifndef EVENTACTION_HH
#define EVENTACTION_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"

#include "g4root.hh"

#include "runaction.hh"

class EventAction : public G4UserEventAction
{
public:
    EventAction(RunAction *);
    ~EventAction();
    
    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);
    
    void AddEdep(G4double edep) { fEdep += edep; } 
    
private:
    G4double fEdep;
};


#endif
