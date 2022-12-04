#ifndef ScatPolPhysicsList_h
#define ScatPolPhysicsList_h 1

#include "G4VModularPhysicsList.hh"

class G4VPhysicsConstructor;

class ScatPolPhysicsList: public G4VModularPhysicsList
{
	public:

		ScatPolPhysicsList();
		virtual ~ScatPolPhysicsList();

		virtual void ConstructParticle();
		virtual void ConstructProcess();

	private:
		G4VPhysicsConstructor* fScatPolPhysicsList;  // Define the physics constructor globally

};
#endif

