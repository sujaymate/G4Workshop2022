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
  G4NistManager*  nist = G4NistManager::Instance();
 
  G4bool checkOverlaps = true;
 
  G4String symbol;
  G4int ncomponents;
  G4double fractionmass;
  G4double a;  
  G4double z;  
  G4double density;

// Plastic scintillator material definition: Vinyl Toluene

  G4Element* C  = new G4Element("Carbon",symbol="C" , z= 6., a= 12.0107*g/mole);
  G4Element* H  = new G4Element("Hydrogen",symbol="H" , z= 1.,a=1.01*g/mole);

  G4Material* VT =new G4Material("VinylToluene", density = 1.032*g/cm3, ncomponents = 2);
  VT->AddElement(C, fractionmass=0.915000);
  VT->AddElement(H, fractionmass=0.085000);


// World material

  G4double universe_mean_density=1.e-25*g/cm3;
  
  G4Material* Vacuum =new G4Material("Galactic", z=1., a=1.01*g/mole,density= universe_mean_density,
                           kStateGas, 2.73*kelvin, 3.e-18*pascal);


// -----------------------------------World Volume------------------------------------------

  G4double world_x,world_y,world_z;
  world_x=100.,world_y=100.,world_z=100.;

  G4Box* solidWorld = new G4Box("Polarimeter_box",world_x,world_y,world_z);
  G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld,Vacuum,"Polarimeter_log",0,0,0);
  G4VisAttributes* logicWorld_VisAtt = new G4VisAttributes(false);
  logicWorld->SetVisAttributes(logicWorld_VisAtt);

  G4VPhysicalVolume* physiWorld = new G4PVPlacement(0,G4ThreeVector(),
                                      logicWorld,"World",0,false,0);
//-------------------------------------------------------------------------------------------

//-----------------------------------Plastic scintillator-----------------------------------
  G4double inrad_PlScint = 0.0*mm;
  G4double outrad_PlScint=0.5*mm;
  G4double height_PlScint=50.0*mm;  

  G4double startAngleOf_PlScint = 0.0*degree;
  G4double spanningAngleOf_PlScint = 360.0*degree;

  G4Tubs* PlScint = new G4Tubs("PlScint",inrad_PlScint,
                outrad_PlScint,0.5*height_PlScint, startAngleOf_PlScint,
                spanningAngleOf_PlScint);


  G4LogicalVolume* logicPlScint;
  G4VisAttributes* logicPlScint_VisAtt;
  
  logicPlScint = new G4LogicalVolume(PlScint,VT,"logicPlScint",0,0,0);
  
  logicPlScint_VisAtt = new G4VisAttributes(
                                      G4Colour(G4Colour::Magenta()));
  
  logicPlScint_VisAtt->SetForceSolid(true);
  logicPlScint->SetVisAttributes(logicPlScint_VisAtt);

  G4double PlScint_Xpos = 0.0*mm;
  G4double PlScint_Ypos = 0.0*mm;
  G4double PlScint_Zpos = -(height_PlScint)/2.0;

  G4ThreeVector PlScint_pos(PlScint_Xpos,PlScint_Ypos,PlScint_Zpos);

  G4VPhysicalVolume* physiPlScint = new G4PVPlacement(0,PlScint_pos,logicPlScint, "PlScatterer",logicWorld,false,0);

  return physiWorld;

}
