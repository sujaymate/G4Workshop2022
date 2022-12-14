#include "ScatPolPhysicsList.hh"

#include "G4EmLivermorePolarizedPhysics.hh"

ScatPolPhysicsList::ScatPolPhysicsList()
    : G4VModularPhysicsList(), fScatPolPhysicsList(0)
{
    // Register a new physic list to the physics constructor
	fScatPolPhysicsList = new G4EmLivermorePolarizedPhysics();
    RegisterPhysics(fScatPolPhysicsList);
}

//***********************************************/

ScatPolPhysicsList::~ScatPolPhysicsList()
{
	delete fScatPolPhysicsList;
}

//***********************************************/

void ScatPolPhysicsList::ConstructParticle()
{
	fScatPolPhysicsList->ConstructParticle();
}

//***********************************************/

void ScatPolPhysicsList::ConstructProcess()
{
    AddTransportation();
    fScatPolPhysicsList->ConstructProcess();
}

