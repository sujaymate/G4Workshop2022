#ifndef HGCALDETECTOR_HH
#define HGCALDETECTOR_HH

#include <G4VUserDetectorConstruction.hh>
#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4VPhysicalVolume.hh>
#include <G4SystemOfUnits.hh>
#include <G4NistManager.hh>
#include <G4PVPlacement.hh>
#include <G4GenericMessenger.hh>

#include "sensitivedetector.hh"

class HGCalDetector : public G4VUserDetectorConstruction
{
public:
  HGCalDetector();
  ~HGCalDetector();
  
  virtual G4VPhysicalVolume *Construct();
  
  void ConstructCassettes();

  G4LogicalVolume *GetScoringVolume() const { return fScoringVolume; }
  
private:
  void DefineMaterials();
  virtual void ConstructSDandField();
  
  //Items related to world volume
  G4Box *worldBox;
  G4LogicalVolume *logicalWorld;
  G4VPhysicalVolume *physicalWorld;
  G4double xWorld, yWorld, zWorld;
  G4Material *worldMat;

  //Items related to cassettes
  G4Box *cassetteBox;
  G4LogicalVolume *logicalCassette;
  G4VPhysicalVolume *physicalCassette;
  G4double xCassette, yCassette, zCassette;
  
  G4Box *cuBox;
  G4LogicalVolume *logicalCu;
  G4double xCu, yCu, zCu;

  G4Box *cuwBox;
  G4LogicalVolume *logicalCuW;
  G4double xCuW, yCuW, zCuW;

  G4Box *pbBox;
  G4LogicalVolume *logicalPb;
  G4double xPb, yPb, zPb;

  G4Box *siBox;
  G4LogicalVolume *logicalSi;
  G4double xSi, ySi, zSi;
  G4int nRows, nCols;

  G4double cassetteThickness ;
  G4Material *CuW, *Cu, *Pb, *Si;

  G4LogicalVolume *fScoringVolume;
  G4GenericMessenger *fMessenger;
};

#endif
