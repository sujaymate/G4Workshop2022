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
  
    // Get particle name, process name,prestepvolume name,trackid, post step energy, and post step momentum for aStep
   
    // If process is compt or Rayl for primary gamma (what would the trackid?), record the 
    // scattered photon energy and momentum. 

}

