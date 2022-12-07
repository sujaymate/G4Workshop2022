#include "actioninit.hh"

ActionInit::ActionInit()
{
}

ActionInit::~ActionInit()
{
}

void ActionInit::BuildForMaster() const
{
    RunAction *runAction = new RunAction();
    SetUserAction(runAction);
}

void ActionInit::Build() const
{
  ParticleGun *pgun = new ParticleGun();
  SetUserAction(pgun);

  RunAction *runAction = new RunAction();
  SetUserAction(runAction);

  EventAction *eventAction = new EventAction(runAction);
  SetUserAction(eventAction);

  SteppingAction *steppingAction = new SteppingAction(eventAction);
  SetUserAction(steppingAction);

}
