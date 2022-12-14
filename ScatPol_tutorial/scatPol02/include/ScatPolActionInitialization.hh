#ifndef ScatPolACTIONINITIALIZATION_H
#define ScatPolACTIONINITIALIZATION_H

#include "G4VUserActionInitialization.hh"

class ScatPolPrimaryGeneratorAction;

class ScatPolActionInitialization: public G4VUserActionInitialization
{
	public:

		ScatPolActionInitialization();
		virtual ~ScatPolActionInitialization();

		virtual void Build() const;

};
#endif
