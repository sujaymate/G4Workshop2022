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
 
// Plastic scintillator material definition: Vinyl Toluene. 
// Define as material made up of Carbon and Hydrogen in fractional masses  


// Use this for material filling world volume

  G4double universe_mean_density=1.e-25*g/cm3;
  
  G4Material* Vacuum =new G4Material("Galactic", z=1., a=1.01*g/mole,density= universe_mean_density,
                           kStateGas, 2.73*kelvin, 3.e-18*pascal);

// Define world volume large enough to accomodate the detector    


// Define plastic scintillator solid, logical volume and physical volume

// always return physical volume of world

}
