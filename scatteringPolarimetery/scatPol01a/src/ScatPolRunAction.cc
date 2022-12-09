
#include "ScatPolRunAction.hh"
#include "ScatPolDetectorConstruction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include <iomanip>
//#include <fstream.h>
#include <fstream>

#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ScatPolRunAction::ScatPolRunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ScatPolRunAction::~ScatPolRunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ScatPolRunAction::BeginOfRunAction(const G4Run* aRun)
{

    auto analysisManager = G4AnalysisManager::Instance();
    G4cout << "Using " << analysisManager->GetType() << G4endl;
    analysisManager->SetVerboseLevel(1);

    G4int runID = aRun->GetRunID();

    std::stringstream fname;
    fname << "sim_output_" << std::setw(2) << std::setfill('0') << runID;

    analysisManager->SetFileName(fname.str());  // Set root filename
    analysisManager->OpenFile();

    // create the ntuple
    analysisManager->CreateNtuple("ComptScat", "Compton scattered photon distribution");
    analysisManager->CreateNtupleIColumn("eventID");
    analysisManager->CreateNtupleFColumn("px");
    analysisManager->CreateNtupleFColumn("py");
    analysisManager->CreateNtupleFColumn("pz");
    analysisManager->CreateNtupleFColumn("scatPhotEne");
    analysisManager->FinishNtuple(0);

    analysisManager->CreateNtuple("RaylScat", "Rayleigh scattered photon distribution");
    analysisManager->CreateNtupleIColumn("eventID");
    analysisManager->CreateNtupleFColumn("px");
    analysisManager->CreateNtupleFColumn("py");
    analysisManager->CreateNtupleFColumn("pz");
    analysisManager->CreateNtupleFColumn("scatPhotEne");
    analysisManager->FinishNtuple(1);


}


void ScatPolRunAction::EndOfRunAction(const G4Run* aRun)
{

    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
    delete G4AnalysisManager::Instance();

}

