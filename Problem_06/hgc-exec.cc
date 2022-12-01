#include <iostream>

#include <G4RunManager.hh>
#include <G4UIExecutive.hh>
#include <G4VisExecutive.hh>
#include <G4VisManager.hh>
#include <G4UImanager.hh>
#include <FTFP_BERT.hh>

#include "hgcaldetector.hh"
#include "actioninit.hh"

int main(int argc, char **argv)
{
  
  G4RunManager *runManager = new G4RunManager();
  
  runManager->SetUserInitialization(new HGCalDetector());

  // The following two line needs to be added to avoid "core dump"
  G4VModularPhysicsList* physics = new FTFP_BERT();
  runManager->SetUserInitialization(physics);

  //This action initializes  particle gun
  runManager->SetUserInitialization(new ActionInit());

  // The following line needs to be added to take the detector, physics list and action initialization into account
  runManager->Initialize();

  G4UIExecutive *ui = new G4UIExecutive(argc, argv);
  
  G4VisManager *visManager = new G4VisExecutive();
  visManager->Initialize();

  G4UImanager *UImanager = G4UImanager::GetUIpointer();

  // The following line displays the geometry
  UImanager->ApplyCommand("/vis/open OGL");
  UImanager->ApplyCommand("/vis/drawVolume");
  // Optionally uncomment to set the viewpoint
  //UImanager->ApplyCommand("/vis/viewer/set/viewpointVector -1 -1 1");
  //To see the trajectories
  UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
  UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
  UImanager->ApplyCommand("/vis/scene/add/scale 2 m");
  UImanager->ApplyCommand("/vis/scene/add/axes");
  UImanager->ApplyCommand("/vis/scene/add/eventID");
  //UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate");

  ui->SessionStart();
  
  return true;
}
