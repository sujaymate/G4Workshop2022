
#ifndef ScatPolPrimaryGeneratorAction_h
#define ScatPolPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"

class G4GeneralParticleSource;
class G4Event;

class ScatPolPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    ScatPolPrimaryGeneratorAction();
    ~ScatPolPrimaryGeneratorAction();

  public:
    void GeneratePrimaries(G4Event* anEvent);

  private:

    G4GeneralParticleSource* particleGun;
};

#endif


