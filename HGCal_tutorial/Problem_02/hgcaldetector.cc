#include "hgcaldetector.hh"

HGCalDetector::HGCalDetector()
{
  xWorld = 40.*m;
  yWorld = 40.*m;
  zWorld = 20.*m;
  
  DefineMaterials();
}

HGCalDetector::~HGCalDetector()
{
}

void HGCalDetector::DefineMaterials(){
  
  G4NistManager *nist = G4NistManager::Instance();
  
  worldMat = nist->FindOrBuildMaterial("G4_AIR");
  
  // Cu = nist->FindOrBuildElement("Cu");
  // Pb = nist->FindOrBuildElement("Pb");
  
  // CuW = new G4Material("CuW", 14.979*g/cm3, 2);  
  // CuW->AddElement(nist->FindOrBuildElement("Cu"), 75*perCent);
  // CuW->AddElement(nist->FindOrBuildElement("W"), 25*perCent);
  
  
}

G4VPhysicalVolume *HGCalDetector::Construct()
{
    worldBox = new G4Box("worldBox", xWorld, yWorld, zWorld);

    logicalWorld = new G4LogicalVolume(worldBox, worldMat, "logicalWorld");

    physicalWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicalWorld, "physicalWorld", 0, false, 0, true);
    
    return physicalWorld;
}
