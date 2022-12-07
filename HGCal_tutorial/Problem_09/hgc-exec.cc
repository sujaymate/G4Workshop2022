#include <iostream>

#include <G4RunManager.hh>
#include <G4MTRunManager.hh>
#include <G4UIExecutive.hh>
#include <G4VisExecutive.hh>
#include <G4VisManager.hh>
#include <G4UImanager.hh>
#include <FTFP_BERT.hh>

#include "hgcaldetector.hh"
#include "actioninit.hh"

int main(int argc, char **argv)
{

#ifdef G4MULTITHREADED
  G4MTRunManager* runManager = new G4MTRunManager;
#else
  G4RunManager* runManager = new G4RunManager;
#endif

  runManager->SetUserInitialization(new HGCalDetector());

  // The following two line needs to be added to avoid "core dump"
  G4VModularPhysicsList* physics = new FTFP_BERT();
  runManager->SetUserInitialization(physics);

  //This action initializes  particle gun
  runManager->SetUserInitialization(new ActionInit());

  // The following line needs to be added to take the detector, physics list and action initialization into account
  // comment out the initialize
  //runManager->Initialize();

  G4UIExecutive* ui = 0;
  if (argc == 1){
    runManager->Initialize();
    ui = new G4UIExecutive(argc, argv);  
    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();
  }
  
  G4UImanager *UImanager = G4UImanager::GetUIpointer();

  if(ui){
    UImanager->ApplyCommand("/control/execute vis.mac");
    ui->SessionStart();
  }else{
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  

  
  return true;
}
