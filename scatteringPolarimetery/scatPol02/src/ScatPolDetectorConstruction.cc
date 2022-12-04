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

G4int ScatPolDetectorConstruction::CheckInteractionVol(G4String& volName){

G4int rtnval;


   if (volName == "PlScatterer")
        rtnval = 100;
   else if (volName.contains("Scint_"))
        rtnval = 200;
   else if(volName == "World")
        rtnval = 999;
   else
        rtnval = 0;

   return rtnval;
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

  G4Element* Cs  = new G4Element("Cesium",symbol="Cs" , z= 55., a= 132.9054519*g/mole);
  G4Element* I  = new G4Element("Iodine",symbol="I" , z= 53., a= 126.90447*g/mole);
  G4Element* Tl  = new G4Element("Thallium",symbol="Tl" , z= 81., a= 204.3833*g/mole);
  G4Element* C  = new G4Element("Carbon",symbol="C" , z= 6., a= 12.0107*g/mole);
  G4Element* H  = new G4Element("Hydrogen",symbol="H" , z= 1.,a=1.01*g/mole);

// CsI(Tl) definition

  G4Material* CsITl = new G4Material("CsITl", density = 4.51*g/cm3, ncomponents = 3);
  CsITl->AddElement(Cs, fractionmass=0.510549);
  CsITl->AddElement(I, fractionmass=0.480451);
  CsITl->AddElement(Tl, fractionmass=0.009000);

// Plastic scintillator definition

  G4Material* VT =new G4Material("VinylToluene", density = 1.032*g/cm3, ncomponents = 2);
  VT->AddElement(C, fractionmass=0.915000);
  VT->AddElement(H, fractionmass=0.085000);


// Vacuum

  G4double universe_mean_density=1.e-25*g/cm3;
  
  G4Material* Vacuum =new G4Material("Galactic", z=1., a=1.01*g/mole,density= universe_mean_density,
                           kStateGas, 2.73*kelvin, 3.e-18*pascal);

  G4double world_x,world_y,world_z;

//****************************************************************************************
// ------------------------ Parameters of simulation geometry-----------------------------
//****************************************************************************************
  G4int num_of_det ; //= 16;
  G4double width_det = 20.*mm;
  G4double thick_det = 5.*mm;
  G4double height_det = 100.*mm;
  G4double radius; // = 58.0*mm;

  G4double outrad_PlScint;  	// = 15*mm;
  G4double height_PlScint; 	// = 70.0*mm;


  // Reading some parameters from a text file  

  FILE *finp;
  finp=fopen("scat_abs_parameters.txt","r");
  
  fscanf(finp,"%lf\t%lf\t%d\t%lf\n",&outrad_PlScint,&height_PlScint, &num_of_det, &radius);

//-----------------------------------------------------------------------------------------
  
// -----------------------------------World Volume------------------------------------------
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
  G4double PlScint_Zpos = -(height_det-height_PlScint)/2.0;

  G4ThreeVector PlScint_pos(PlScint_Xpos,PlScint_Ypos,PlScint_Zpos);

  G4VPhysicalVolume* physiPlScint = new G4PVPlacement(0,PlScint_pos,logicPlScint, "PlScatterer",logicWorld,false,0);

//-----------------------------------------------------------------------------------------------

//---------------------------------CsI(Tl) scintillators-----------------------------------------


  // Define solid and log volume for scintillator
  G4Box* solidScintBox = new G4Box("ScintBox", 0.5*width_det, 0.5*thick_det,0.5*height_det);
  
  G4LogicalVolume* logicScintBox = new G4LogicalVolume(solidScintBox,CsITl,"ScintBox",0,0,0);
  G4VisAttributes* logicScintBox_VisAtt = new G4VisAttributes(
                                        G4Colour(G4Colour::Yellow()));
  logicScintBox_VisAtt->SetForceSolid(true);
  logicScintBox->SetVisAttributes(logicScintBox_VisAtt);


  // Place scintillators around plastic scintillator at equal angles
  // Note that
  G4int j;
  G4String scintName = "Scint_NN";
  G4String Alname = "Al";
  char* tmpStr = new char[25];
  G4double ang,pos_X,pos_Y,pos_Z;

  for (j=0;j<num_of_det;j++)
  {
    ang = j*2.0*M_PI/(num_of_det);
    
    //position  of the scintillator center
    pos_X = radius*sin(ang);
    pos_Y = radius*cos(ang);
    pos_Z = 0.0*mm;
    G4ThreeVector Scint_pos(pos_X,pos_Y,pos_Z);

    // Rotation matrix of scintillator as well  as the Al front and side
    G4RotationMatrix rot_Scint;
    rot_Scint.rotateZ(-ang);


    sprintf(tmpStr, "Scint_%02d\0", j);
    scintName = tmpStr;
    
    //G4cout << "*Scintillator Number*  " << scintName <<  "  " << j << G4endl;

    G4VPhysicalVolume* physiScintBox = new G4PVPlacement(G4Transform3D(rot_Scint,Scint_pos),logicScintBox,scintName,logicWorld,false,0);
    
  }  

//-----------------------------------------------------------------------------------------------

  return physiWorld;
}
