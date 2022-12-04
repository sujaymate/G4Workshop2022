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
//#include "G4ThreeVector.hh"

//#include "G4Step.hh"
//#include "G4String.hh"
//#include "G4StepPoint.hh"

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

    G4int intvol = detector->CheckInteractionVol(preStepVolName);

    G4String scNo;
    int ScintN;
    G4double edep_Sc;  

    // get particle name
    G4String particle = aStep->GetTrack()->GetDefinition()->GetParticleName();

    // get process name
    G4String process;
    if(aStep->GetPostStepPoint()->GetProcessDefinedStep() != 0){
        process = aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
    } else {
        process = "Unknown";
    }

 
    if(intvol==100)
    {
        if (process =="phot")
           event->AddphotPl();
        else if (process =="compt")
           event->AddcomptPl();
        else if (process =="Rayl")
           event->AddraylPl();
       
        if(particle=="e-") 
            event->AddEdepPl((aStep->GetTotalEnergyDeposit())/keV);

    }

    else if(intvol==200)
    {
        if (process =="phot")
           event->AddphotSc();
        else if (process =="compt")
           event->AddcomptSc();
        else if (process =="Rayl")
           event->AddraylSc();

        if(particle=="e-")
           event->AddEdepSc((aStep->GetTotalEnergyDeposit())/keV);
        else if (particle=="gamma")
           {
           scNo=(preStepVolName.substr(6, 2));
           ScintN=std::atoi(scNo);

           event->SetScint(ScintN); 
           }

     }


}

