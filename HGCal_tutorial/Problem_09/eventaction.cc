#include "eventaction.hh"

EventAction::EventAction(RunAction*)
{
    fEdep = 0.;
}

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event*)
{
    fEdep = 0.;
}

void EventAction::EndOfEventAction(const G4Event*)
{
#ifndef G4MULTITHREADED
  G4cout << "Energy deposition: " << fEdep/(MeV) << " MeV" << G4endl;
#endif
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->FillNtupleDColumn(2, 0, fEdep/MeV);

    man->AddNtupleRow(2);
}
