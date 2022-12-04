
#include "ScatPolEventAction.hh"
#include "ScatPolRunAction.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4VTrajectory.hh"
#include "G4VVisManager.hh"
#include "G4UnitsTable.hh"
#include "G4RunManager.hh"

#include <iomanip>
#include "G4ThreeVector.hh"


ScatPolEventAction::ScatPolEventAction()
{  
    runAct = (ScatPolRunAction*)G4RunManager::GetRunManager()->GetUserRunAction();
}


ScatPolEventAction::~ScatPolEventAction()
{
}

void ScatPolEventAction::BeginOfEventAction(const G4Event* evt)
{

}


void ScatPolEventAction::EndOfEventAction(const G4Event* evt)
{

}  

