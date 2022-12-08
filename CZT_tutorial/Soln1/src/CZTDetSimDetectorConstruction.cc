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
 *  CZTDetSimDetectorConstruction.cc
 *  
 */

// Necessary geometry classes
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"

// Includes for material and unit definitions
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"

// Geometry shape header files
#include "G4Orb.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"

// Detector construction headers
#include "CZTDetSimDetectorConstruction.hh"
#include "CZTDetSimSD.hh"
#include "CADMesh.hh"

CZTDetSimDetectorConstruction::CZTDetSimDetectorConstruction()
    : G4VUserDetectorConstruction()
{ 

}

//***********************************************/

CZTDetSimDetectorConstruction::~CZTDetSimDetectorConstruction()
{
    
}

//***********************************************/

G4VPhysicalVolume* CZTDetSimDetectorConstruction::Construct()
{
    //Get material list pointer
	G4NistManager* nistManager = G4NistManager::Instance();

    // Build  materials directly from the NIST manager
    G4Material* galactic = nistManager->FindOrBuildMaterial("G4_Galactic");
    G4Material* Cd = nistManager->FindOrBuildMaterial("G4_Cd");
    G4Material* Zn = nistManager->FindOrBuildMaterial("G4_Zn");
    G4Material* Te = nistManager->FindOrBuildMaterial("G4_Te");
    G4Material* Ta = nistManager->FindOrBuildMaterial("G4_Ta");

    G4Material* CZT = new G4Material("CZT",5.78*g/cm3, 3);

	CZT->AddMaterial(Cd, 0.430016);
	CZT->AddMaterial(Te, 0.542194);
	CZT->AddMaterial(Zn, 0.027790);
    
    //Define World
	G4double wR = 10.0*m; // world radius

    //Create world volume (Sphere of radius 1 m having intergalactic material density)
    // Define the solid shape
	G4Orb* worldS = new G4Orb("world", wR);

    // Define its logical volume
    G4LogicalVolume* worldLV = new G4LogicalVolume(worldS, galactic, "World");

    // Place
    G4VPhysicalVolume* worldPV = new G4PVPlacement(0,
								                   G4ThreeVector(),
												   worldLV,
												   "World",
												   0,
												   false,
												   0,
												   true);


    // Build CZT wafer
    G4double hx = 3.936*cm;
    G4double hy = 3.936*cm;
    G4double hz = 5.*mm;

    G4VSolid* CZTWaferS = new G4Box("CZTWaferS", hx/2., hy/2., hz/2.);

    CZTWaferLV = new G4LogicalVolume(CZTWaferS, CZT, "CZTWaferLV");

    G4VPhysicalVolume* CZTWaferPV = new G4PVPlacement(0,
                                                G4ThreeVector(0, 0, 0),
                                                CZTWaferLV,
                                                "CZT_Wafer",
                                                worldLV,
                                                false,
                                                0,
                                                true);

    // Set visualisation attributes    
    G4VisAttributes *CZTWaferVisatt = new G4VisAttributes(G4Color::Green());
    CZTWaferVisatt->SetForceSolid();
    CZTWaferLV->SetVisAttributes(CZTWaferVisatt);

    // CADMesh import
    auto MaskMesh = CADMesh::TessellatedMesh::FromSTL("../G4Workshop2022/CZT_tutorial/Soln1/mask/CAM.stl");
    G4VSolid* MaskS = MaskMesh->GetSolid();
    G4LogicalVolume* MaskLV = new G4LogicalVolume(MaskS, Ta, "MaskLV");
    G4VPhysicalVolume* mask = new G4PVPlacement(0,
                                                G4ThreeVector(0, 0, 5.*cm),
                                                MaskLV,
                                                "Mask",
                                                worldLV,
                                                false,
                                                0,
                                                true);

    // Set visualisation attributes    
    G4VisAttributes *MaskVisatt = new G4VisAttributes(G4Color::Red());
    MaskVisatt->SetForceSolid();
    MaskLV->SetVisAttributes(MaskVisatt);

    return worldPV;  // Always return the world volume !!!!!
}

void CZTDetSimDetectorConstruction::ConstructSDandField()
{
    CZTDetSimSD* CZTSD = new CZTDetSimSD("CZTSD", "CZTDetSimHitsCollection");  // Add SD and hits collection name 
    G4SDManager::GetSDMpointer()->AddNewDetector(CZTSD);
    SetSensitiveDetector("CZTWaferLV", CZTSD);
}

