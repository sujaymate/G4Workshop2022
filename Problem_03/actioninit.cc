#include "actioninit.hh"

ActionInit::ActionInit()
{
}

ActionInit::~ActionInit()
{
}

void ActionInit::Build() const
{
  ParticleGun *pgun = new ParticleGun();
  SetUserAction(pgun);
}
