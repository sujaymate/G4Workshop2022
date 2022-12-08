#include "ScatPolDetectorConstruction.hh"

#include "G4SystemOfUnits.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4PVPlacement.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4NistManager.hh"
#include "G4AssemblyVolume.hh"
#include "G4AssemblyTriplet.hh"

#include "G4VSolid.hh"


#include <iostream>
#include <fstream>
using namespace std;

ScatPolDetectorConstruction::ScatPolDetectorConstruction()
{
}

ScatPolDetectorConstruction::~ScatPolDetectorConstruction()
{
}

//DETECTOR CONSTRUCTION

G4VPhysicalVolume* ScatPolDetectorConstruction::Construct()
{

// Use this for material filling world volume - G4_GALACTIC

  G4NistManager*  nist = G4NistManager::Instance();
  G4Material* galacticMat= nist->FindOrBuildMaterial("G4_GALACTIC");

/*
  G4double universe_mean_density=1.e-25*g/cm3;
  
  G4Material* Vacuum =new G4Material("Galactic", z=1., a=1.01*g/mole,density= universe_mean_density,
                           kStateGas, 2.73*kelvin, 3.e-18*pascal);
*/

// Define world volume large enough to accomodate the detector    

  G4double world_x,world_y,world_z;
  world_x=100.,world_y=100.,world_z=100.;

  G4Box* solidWorld = new G4Box("Polarimeter_box",world_x,world_y,world_z);
  G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld,galacticMat,"Polarimeter_log",0,0,0);
  //G4VisAttributes* logicWorld_VisAtt = new G4VisAttributes(false);
  //logicWorld->SetVisAttributes(logicWorld_VisAtt);

  G4VPhysicalVolume* physiWorld = new G4PVPlacement(0,G4ThreeVector(),
                                      logicWorld,"World",0,false,0);

// Plastic scintillator material definition: Vinyl Toluene. 
// Define as material made up of Carbon and Hydrogen in fractional masses or get it 
// from NIST manager 


// Define plastic scintillator solid, logical volume and physical volume

// always return physical volume of world

	return physiWorld;
}
