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

#include "string.h"

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

    G4Material* CZT = new G4Material("CZT",5.78*g/cm3, 3);

	CZT->AddMaterial(Cd, 0.430016);
	CZT->AddMaterial(Te, 0.542194);
	CZT->AddMaterial(Zn, 0.027790);
    
     G4double a,z,density;
     G4String name, symbol;
     G4int nel,ncomp,natoms;
     a=1.01*g/mole;
     G4Element* elH = new G4Element(name="Hydrogen", symbol="H", z=1 ,a);
     a = 28.09*g/mole;
     G4Element* elSi = new G4Element(name="Silicon",symbol="Si",z=14.,a);
  /*   a=47.90*g/mole;
     G4Element* elTi = new G4Element(name="Titanium",symbol="Ti",z=22.,a);*/
     a = 26.98*g/mole;
     G4Element* elAl = new G4Element(name="Aluminum",symbol="Al",z=13.,a);

     a = 24.31*g/mole;
     G4Element* elMg = new G4Element(name="Magnesium",symbol="Mg",z=12.,a);
     a = 30.97*g/mole;
     G4Element* elP = new G4Element(name="Phosphorus",symbol="P",z=15.,a);
     a = 16.00*g/mole;
     G4Element* elO = new G4Element(name="Oxygen",symbol="O",z=8.,a);
     a = 58.71*g/mole;
     G4Element* elNi = new G4Element(name="Nickel",symbol="Ni",z=28.,a);
     a = 14.01*g/mole;
     G4Element* elN = new G4Element(name="Nitrogen", symbol="N", z=7., a);
     a = 12.0107*g/mole;
     G4Element* elC = new G4Element(name="Carbon",symbol="C",z=6.,a);
     a = 114.818*g/mole;
     G4Element* elInd = new G4Element(name="Indium",symbol="In",z=49.,a);
     // SiO2
         density = 2.2*g/cm3;
         G4Material* silica = new G4Material(name = "silica",density,nel=2);
         silica->AddElement(elSi,natoms=1);
         silica->AddElement(elO,natoms=2);

     // Epoxy
         density = 1.2*g/cm3;
         G4Material* epoxy = new G4Material(name = "epoxy",density,nel=2);
         epoxy->AddElement(elH,natoms=2);
         epoxy->AddElement(elC,natoms=2);

    // FR4 (flame retardant4) PCB material
        density = 1.86*g/cm3;
        G4Material* FR4 = new G4Material(name="FR4",density,ncomp=2);
        FR4->AddMaterial(silica,0.528);
        FR4->AddMaterial(epoxy,0.472);
    //Kapton
        density = 1.42*g/cm3;
        G4Material* kapton = new G4Material(name="kapton",density,ncomp=4);
        kapton->AddElement(elH,0.0273);
        kapton->AddElement(elC,0.7213);
        kapton->AddElement(elN,0.0765);
        kapton->AddElement(elO,0.1749);

   // indium
        density = 7.31*g/cm3;
        G4Material* matInd = new G4Material(name="MatIndium",density,nel=1);
        matInd->AddElement(elInd,100*perCent);

   // Al 6061
       density = 2.7*g/cm3;
       G4Material* Al6061 = new G4Material(name = "Al6061",density, nel=4);
       Al6061->AddElement(elAl,98.*perCent);
       Al6061->AddElement(elMg,1.*perCent);
       Al6061->AddElement(elSi,0.6*perCent);
       Al6061->AddElement(elAl,0.4*perCent);

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



    // A 100 micron of Al is placed above the device as its optical light-tight filter:
    // This also avoids incidence of soft X-rays leading to pileup in CZT detector:

    double cztSizeX = 2.5*mm;
    double cztSizeY = 2.5*mm;
    double cztSizeZ = 5.*mm;

        double Alsheet_X = 50*mm;
        double Alsheet_Y = 50*mm;
        double Alsheet_Z = 100*micrometer;

        G4VSolid* Alsheetsolid = new G4Box("Al_sheet",Alsheet_X/2.,Alsheet_Y/2.,Alsheet_Z/2.);
        G4LogicalVolume* logicAlsheet = new G4LogicalVolume(Alsheetsolid,Al6061,"Al_sheet");
        new G4PVPlacement(0,
                      G4ThreeVector(0.*mm,0.*mm,5*mm),
                  "Al_sheet",
                  logicAlsheet,
                  worldPV,
                  false,
                  0);


 // Include the layers at the top of the CZT active volume:

// Polyester : Logo label of the manufacturer

    double logoSizeX = 40*mm;
    double logoSizeY = 40*mm;
    double logoSizeZ = 150.*micrometer;


    G4Box* solidlogo = new G4Box("logo_label",logoSizeX/2.,logoSizeY/2.,logoSizeZ/2.);
    G4LogicalVolume* logiclogo = new G4LogicalVolume(solidlogo,FR4,"logo_label");

    new G4PVPlacement(0,G4ThreeVector(0,0,((0.5*cztSizeZ)+1)*mm),
                      "logo_label",
                      logiclogo,
                      worldPV,
                      false,
                      0);


// FR4 sheet beneath the logo label :
    double fr4SizeZ = 200.*micrometer;

    G4Box* solidfr4 = new G4Box("fr4",logoSizeX/2.,logoSizeY/2.,fr4SizeZ/2.);
    G4LogicalVolume* logicfr4 = new G4LogicalVolume(solidfr4,FR4,"fr4");

    new G4PVPlacement(0,G4ThreeVector(0,0,((0.5*cztSizeZ)+0.3)*mm),
                      "fr4",
                      logicfr4,
                      worldPV,
                      false,
                      0);


// Indium electrode contact :
    double IndSizeZ = 0.5*micrometer;

    G4Box* solidind = new G4Box("Indium_contact",logoSizeX/2.,logoSizeY/2.,IndSizeZ/2.);
    G4LogicalVolume* logicind = new G4LogicalVolume(solidind,matInd,"Indium_contact");

    new G4PVPlacement(0,G4ThreeVector(0,0,((0.5*cztSizeZ)+0.1)*mm),
                      "Indium_contact",
                      logicind,
                      worldPV,
                      false,
                      0);




// CZT detector




    double pixelPitch = 2.5*mm;

    G4Box* solidCZT = new G4Box("czt",cztSizeX/2.,cztSizeY/2.,cztSizeZ/2.);
    G4LogicalVolume* logicCZT = new G4LogicalVolume(solidCZT,CZT,"cztlv");


    double initial_x1 = (-20 + 1.25)*mm;
    double initial_y1 = (-20 +1.25)*mm;

    for(int i1=0;i1<16;i1++)
    {
        for(int j1=0;j1<16;j1++)

        {
            int k1 = (i1*16)+j1;
            new G4PVPlacement(0,
                      G4ThreeVector((initial_x1+(pixelPitch*j1))*mm,(initial_y1+(pixelPitch*i1))*mm,0*mm),
                      "czt",
                      logicCZT,
                      worldPV,
                      false,
                      k1);

        }
     }
    // Set visualisation attributes

    G4VisAttributes *CZTWaferVisatt = new G4VisAttributes(G4Color::Green());
    CZTWaferVisatt->SetForceSolid();
    logicCZT->SetVisAttributes(CZTWaferVisatt);
      /*
        G4SDManager* SDman = G4SDManager::GetSDMpointer();
       G4String  trackerChamberSDname = "CZTSD";
       CZTDetSimSD*  aTrackerSD = new CZTDetSimSD("CZTSD","CZTHitsCollection");
       SDman->AddNewDetector(aTrackerSD);
       logicCZT->SetSensitiveDetector(aTrackerSD);
        */
        return worldPV;





}


void CZTDetSimDetectorConstruction::ConstructSDandField()
{
    CZTDetSimSD* CZTSD = new CZTDetSimSD("CZTSD", "CZTDetSimHitsCollection");  // Add SD and hits collection name
    G4SDManager::GetSDMpointer()->AddNewDetector(CZTSD);
    SetSensitiveDetector("cztlv", CZTSD);
}


