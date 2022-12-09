#include "ScatPolActionInitialization.hh"  
#include "ScatPolPrimaryGeneratorAction.hh"
#include "ScatPolRunAction.hh"
#include "ScatPolSteppingAction.hh"

ScatPolActionInitialization::ScatPolActionInitialization()
    : G4VUserActionInitialization()
{
}

//***********************************************/

ScatPolActionInitialization::~ScatPolActionInitialization()
{
	
}

//***********************************************/

void ScatPolActionInitialization::Build() const
{
    SetUserAction(new ScatPolPrimaryGeneratorAction());

    SetUserAction(new ScatPolRunAction());
    SetUserAction(new ScatPolSteppingAction());
    
}
