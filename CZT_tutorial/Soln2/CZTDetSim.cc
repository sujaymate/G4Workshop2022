/**
 *  ********************************************************************
 *  * License and Disclaimer                                           *
 *  *                                                                  *
 *  * The  Geant4 software  is  copyright of the Copyright Holders  of *
 *  * the Geant4 Collaboration.  It is provided  under  the terms  and *
 *  * conditions of the Geant4 Software License,  included in the file *
 *  * LICENSE and available at  http://cern.ch/geant4/license .  These *
 *  * include a list of copyright holders.                             *
 *  *                                                                  *
 *  * Neither the authors of this software system, nor their employing *
 *  * institutes,nor the agencies providing financial support for this *
 *  * work  make  any representation or  warranty, express or implied, *
 *  * regarding  this  software system or assume any liability for its *
 *  * use.  Please see the license in the file  LICENSE  and URL above *
 *  * for the full disclaimer and the limitation of liability.         *
 *  *                                                                  *
 *  * This  code  implementation is the result of  the  scientific and *
 *  * technical work of the GEANT4 collaboration.                      *
 *  * By using,  copying,  modifying or  distributing the software (or *
 *  * any work based  on the software)  you  agree  to acknowledge its *
 *  * use  in  resulting  scientific  publications,  and indicate your *
 *  * acceptance of all terms of the Geant4 Software license.          *
 *  ********************************************************************
 *  
 *  CZTDetSim.cc
 * 
 */

#include "CZTDetSimDetectorConstruction.hh"
#include "CZTDetSimActionInitialization.hh"
#include "CZTDetSimPrimaryGeneratorAction.hh"
#include "CZTDetSimPhysicsList.hh"
#include "CZTDetSimEventAction.hh"
#include "CZTDetSimRunAction.hh"

#include "G4RunManager.hh"

#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include <iostream>

int main(int argc, char** argv)
{
    // Detect interactive mode (if no arguments) and define UI session
    G4UIExecutive* ui = 0;
    if ( argc == 1 ){
        ui = new G4UIExecutive(argc, argv);
    }
    
    std::cout<<"given directory is : "<< argv[2]<<"\n";
    
    // Construct the run manager
    G4RunManager* runManager = new G4RunManager;
    
    // Choose the Random engine and set time dependent seed
    //CLHEP::RanluxEngine defaultEngine( 1234567, 4 );
    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    G4long seed = time(NULL);
    G4Random::setTheSeed(seed);
    
    // Remove old root files
    //system("rm *.root");

    // Set mandatory initialization classes

    // Detector construction
    runManager->SetUserInitialization(new CZTDetSimDetectorConstruction());

    // Physics List
    runManager->SetUserInitialization(new CZTDetSimPhysicsList());

    // User action Initialization
    G4String tmp_var;
    if (argc == 3){
    tmp_var = argv[2];	// passes the address of the output directory
    }
    else{
	  tmp_var ="";
    }
    runManager->SetUserInitialization(new CZTDetSimActionInitialization(tmp_var));

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
        delete ui;
    }

    // Job termination
    // Free the store: user actions, physics_list and detector_description are
    // owned and deleted by the run manager, so they should not be deleted
    // in the main() program !
    
    delete visManager;
    return 0; 
}
