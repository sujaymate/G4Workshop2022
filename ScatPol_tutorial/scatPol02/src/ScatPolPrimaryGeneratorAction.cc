
#include "ScatPolPrimaryGeneratorAction.hh"

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"


ScatPolPrimaryGeneratorAction::ScatPolPrimaryGeneratorAction()
{
   particleGun = new G4GeneralParticleSource();
}

ScatPolPrimaryGeneratorAction::~ScatPolPrimaryGeneratorAction()
{
  delete particleGun;
}

void ScatPolPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  particleGun->GeneratePrimaryVertex(anEvent) ;
}






