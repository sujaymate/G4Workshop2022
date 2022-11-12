#include "ScatPolSteppingAction.hh"

#include "ScatPolDetectorConstruction.hh"
#include "ScatPolEventAction.hh"

#include "G4SteppingManager.hh"
#include "G4EventManager.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

#include <iostream>
#include <string>  

#include "G4String.hh"
#include "G4ThreeVector.hh"
class G4VProcess;

class G4SteppingManager;


ScatPolSteppingAction::ScatPolSteppingAction()
{ 
  detector = (ScatPolDetectorConstruction*)G4RunManager::GetRunManager()->GetUserDetectorConstruction();

  event = (ScatPolEventAction*)G4RunManager::GetRunManager()->GetUserEventAction();
}


ScatPolSteppingAction::~ScatPolSteppingAction()
{ }


void ScatPolSteppingAction::UserSteppingAction(const G4Step* aStep)
{
    
    G4String preStepVolName = aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName();

    // get particle name
    G4String particle = aStep->GetTrack()->GetDefinition()->GetParticleName();

    // get process name
    G4String process;
    if(aStep->GetPostStepPoint()->GetProcessDefinedStep() != 0){
        process = aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
    } else {
        process = "Unknown";
    }

    //get track id
    G4int trackid=aStep->GetTrack()->GetTrackID();
        
    if(preStepVolName=="PlScatterer" && particle=="gamma" && trackid==1) 
    {
        G4ThreeVector photMomDir=aStep->GetPostStepPoint()->GetMomentumDirection() ;
        G4double photEnergy=aStep->GetPostStepPoint()->GetTotalEnergy()/keV;

        if (process =="compt")
            event->AddcomptPl(photMomDir,photEnergy);
        else if (process =="Rayl")
            event->AddraylPl(photMomDir,photEnergy);
    }

}

