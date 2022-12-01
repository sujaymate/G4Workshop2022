#include "particlegun.hh"

ParticleGun::ParticleGun()
{
  fParticleGun = new G4ParticleGun(1);
}

ParticleGun::~ParticleGun()
{
  delete fParticleGun;
}

void ParticleGun::GeneratePrimaries(G4Event* event)
{
  G4ParticleTable *partTable = G4ParticleTable::GetParticleTable();
  G4String partName = "proton" ;
  G4ParticleDefinition *partDef = partTable->FindParticle(partName);
  
  G4ThreeVector position(0.0, 0.0 , 0.0);
  G4ThreeVector momdir(0.0, 0.0 , 1.0);

  fParticleGun->SetParticleDefinition(partDef);  
  fParticleGun->SetParticlePosition(position);
  fParticleGun->SetParticleMomentumDirection(momdir);
  fParticleGun->SetParticleMomentum(100.*GeV);

  fParticleGun->GeneratePrimaryVertex(event);
}
