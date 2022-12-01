#ifndef HGCALDETECTOR_HH
#define HGCALDETECTOR_HH

#include <G4VUserDetectorConstruction.hh>
#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4VPhysicalVolume.hh>
#include <G4SystemOfUnits.hh>
#include <G4NistManager.hh>
#include <G4PVPlacement.hh>

class HGCalDetector : public G4VUserDetectorConstruction
{
public:
  HGCalDetector();
  ~HGCalDetector();
  
  virtual G4VPhysicalVolume *Construct();
  
private:
  void DefineMaterials();
  
  G4Box *worldBox;
  G4LogicalVolume *logicalWorld;
  G4VPhysicalVolume *physicalWorld;
  
  G4double xWorld, yWorld, zWorld;

  G4Material *worldMat;
  // G4Material *CuW;
  // G4Element *Cu, *Pb;
};

#endif
