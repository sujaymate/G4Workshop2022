#include "sensitivedetector.hh"

SensitiveDetector::SensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{
}

SensitiveDetector::~SensitiveDetector()
{}

G4bool SensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
    G4Track *track = aStep->GetTrack();
    
    G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
    G4StepPoint *postStepPoint = aStep->GetPostStepPoint();
    
    G4ThreeVector posParticle = preStepPoint->GetPosition();
    G4ThreeVector momParticle = preStepPoint->GetMomentum();

    G4double time = preStepPoint->GetGlobalTime();

    //G4cout << "Particle position: " << posParticle/(cm) << G4endl;

    const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

    G4int copyNo = touchable->GetCopyNumber();

    //G4cout << "Copy number: " << copyNo << G4endl;

    G4VPhysicalVolume *physVol = touchable->GetVolume();
    G4ThreeVector posDetector = physVol->GetTranslation();

    //G4cout << "Detector position: " << posDetector/(cm) << G4endl;


    G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->FillNtupleIColumn(0, 0, evt);
    man->FillNtupleDColumn(0, 1, posParticle[0]/cm);
    man->FillNtupleDColumn(0, 2, posParticle[1]/cm);
    man->FillNtupleDColumn(0, 3, posParticle[2]/cm);
    man->FillNtupleDColumn(0, 4, time);
    man->AddNtupleRow(0);
    
    man->FillNtupleIColumn(1, 0, evt);
    man->FillNtupleDColumn(1, 1, posDetector[0]/cm);
    man->FillNtupleDColumn(1, 2, posDetector[1]/cm);
    man->FillNtupleDColumn(1, 3, posDetector[2]/cm);
    man->AddNtupleRow(1);
    
    return true;
}
