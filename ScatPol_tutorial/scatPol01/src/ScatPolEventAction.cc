
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
#include "G4ThreeVector.hh"

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

 G4int evtNb = evt->GetEventID();

 //G4cout<<"Begin of event: "<<evtNb<<G4endl; 

 comptFlag=0,raylFlag=0;   

 evt_data.comptFlag=0;
 evt_data.raylFlag=0;
}

void ScatPolEventAction::AddcomptPl(G4ThreeVector &photMomDir, G4double photEnergy)
{
    if(comptFlag==0 && raylFlag==0)
    {
    comptFlag=1;
    evt_data.comptFlag=1;
    evt_data.scatPhotMomDir=photMomDir;
    evt_data.scatPhotEne=photEnergy;
    }
}

void ScatPolEventAction::AddraylPl(G4ThreeVector &photMomDir, G4double photEnergy)
{
    if(comptFlag==0 && raylFlag==0)
    {    
    raylFlag=1;
    evt_data.raylFlag=1;
    evt_data.scatPhotMomDir=photMomDir;
    evt_data.scatPhotEne=photEnergy;
    }
}


void ScatPolEventAction::EndOfEventAction(const G4Event* evt)
{
    if(comptFlag==1 || raylFlag==1)
        runAct->WritePerEvent(evt_data);
}  

