
#include "ScatPolEventAction.hh"
#include "ScatPolRunAction.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4VTrajectory.hh"
#include "G4VVisManager.hh"
#include "G4UnitsTable.hh"
#include "G4RunManager.hh"

//#include "Randomize.hh"
#include <iomanip>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ScatPolEventAction::ScatPolEventAction()
{  
    runAct = (ScatPolRunAction*)G4RunManager::GetRunManager()->GetUserRunAction();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ScatPolEventAction::~ScatPolEventAction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ScatPolEventAction::BeginOfEventAction(const G4Event* evt)
{

 evt_data.photPl=0;
 evt_data.comptPl=0;
 evt_data.raylPl=0;
 evt_data.photSc=0;
 evt_data.comptSc=0;
 evt_data.raylSc=0;
 evt_data.scint_no=-1;
 evt_data.scint_index=0;
 evt_data.EnePl=0.;
 evt_data.EneSc=0.;
 
 G4int evtNb = evt->GetEventID();

 //G4cout<<"Begin of event: "<<evtNb<<G4endl; 
}


void ScatPolEventAction::EndOfEventAction(const G4Event* evt)
{
    runAct->WritePerEvent(evt_data);
}  

