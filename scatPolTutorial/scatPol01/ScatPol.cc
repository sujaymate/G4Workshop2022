
#include "ScatPolDetectorConstruction.hh"
#include "ScatPolActionInitialization.hh"
#include "ScatPolPrimaryGeneratorAction.hh"
#include "ScatPolPhysicsList.hh"

#include "G4RunManager.hh"

#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"


int main(int argc, char** argv)
{
    // Detect interactive mode (if no arguments) and define UI session
    G4UIExecutive* ui = 0;
    if ( argc == 1 ){
        ui = new G4UIExecutive(argc, argv);
    }
     
    // Construct the run manager & Set initialization classes
    // Detector construction, Physics List, User action Initialization

    G4RunManager* runManager = new G4RunManager;

    runManager->SetUserInitialization(new ScatPolDetectorConstruction());

    runManager->SetUserInitialization(new ScatPolPhysicsList());

    runManager->SetUserInitialization(new ScatPolActionInitialization());
    
    runManager->Initialize();


    // Initialize visualization
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    // Get the pointer to the User Interface manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    // Process macro or start UI session
    if ( ! ui ) { 
        // batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }
    else { 
        // interactive mode
        UImanager->ApplyCommand("/control/execute init_vis.mac");
        ui->SessionStart();
    }

    // Job termination
    // Free the store: user actions, physics_list and detector_description are
    // owned and deleted by the run manager, so they should not be deleted
    // in the main() program !
    
    delete ui;
    delete visManager;
    return 0; 
}

