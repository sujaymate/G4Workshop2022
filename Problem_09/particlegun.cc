#include "particlegun.hh"

ParticleGun::ParticleGun()
{
  fParticleGun = new G4ParticleGun(1);
  G4ParticleTable *partTable = G4ParticleTable::GetParticleTable();
  G4String partName = "proton" ;
  G4double momentum = 100.*GeV ; 

  // fPartMessenger = new G4GenericMessenger(this, "/gun/", "Detector Construction");
  // fPartMessenger->DeclareProperty("particle", partName, "Number of cols");
  // fPartMessenger->DeclareProperty("momentumAmp", momentum, "Number of rows");

  G4ParticleDefinition *partDef = partTable->FindParticle(partName);
  
  G4ThreeVector position(0.0, 0.0 , 0.0);
  G4ThreeVector momdir(0.0, 0.0 , 1.0);

  fParticleGun->SetParticleDefinition(partDef);  
  fParticleGun->SetParticlePosition(position);
  fParticleGun->SetParticleMomentumDirection(momdir);
  fParticleGun->SetParticleMomentum(momentum);

}

ParticleGun::~ParticleGun()
{
  delete fParticleGun;
}

void ParticleGun::GeneratePrimaries(G4Event* event)
{

  fParticleGun->GeneratePrimaryVertex(event);
  G4cout << "==== G4 particle name : " << fParticleGun->GetParticleDefinition()->GetParticleName() << G4endl;
  G4cout << "==== G4 particle mom : " << (fParticleGun->GetParticleMomentum())/(GeV) << " GeV" << G4endl;
}
