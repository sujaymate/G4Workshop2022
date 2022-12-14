#include "ScatPolSteppingAction.hh"
#include "ScatPolDetectorConstruction.hh"

#include "G4RunManager.hh"

#include "G4ThreeVector.hh"
#include "G4SystemOfUnits.hh"

class G4VProcess;


ScatPolSteppingAction::ScatPolSteppingAction()
{ 
  detector = (ScatPolDetectorConstruction*)G4RunManager::GetRunManager()->GetUserDetectorConstruction();
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
    G4bool isFirst=aStep->IsFirstStepInVolume ();
        
    if(preStepVolName=="PlScatterer" && particle=="gamma" && trackid==1 && isFirst && ((process =="compt")||process =="Rayl")) 
    {
        G4ThreeVector photMomDir=aStep->GetPostStepPoint()->GetMomentumDirection() ;
        G4double photEnergy=aStep->GetPostStepPoint()->GetTotalEnergy()/keV;
        G4int evtID =(G4EventManager::GetEventManager())->GetConstCurrentEvent()->GetEventID();       

        G4int tupleID=-1;

        if (process =="compt")
            tupleID=0;
        else if (process =="Rayl")
            tupleID=1;

        auto analysisManager = G4AnalysisManager::Instance();
        analysisManager->FillNtupleIColumn(tupleID, 0, evtID);
        analysisManager->FillNtupleFColumn(tupleID, 1, photMomDir[0]);
        analysisManager->FillNtupleFColumn(tupleID, 2, photMomDir[1]);
        analysisManager->FillNtupleFColumn(tupleID, 3, photMomDir[2]);
        analysisManager->FillNtupleFColumn(tupleID, 4, (float)photEnergy);
        analysisManager->AddNtupleRow(tupleID);
            
    }

}

