#ifndef PARTICLEGUN_HH
#define PARTICLEGUN_HH

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>
#include <G4SystemOfUnits.hh>
#include <G4ParticleTable.hh>

class ParticleGun : public G4VUserPrimaryGeneratorAction
{
public:
  ParticleGun();
  ~ParticleGun();

  virtual void GeneratePrimaries(G4Event*);
  
private:
  G4ParticleGun *fParticleGun;

};

#endif
