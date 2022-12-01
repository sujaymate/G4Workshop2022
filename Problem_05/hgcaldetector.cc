#include "hgcaldetector.hh"

HGCalDetector::HGCalDetector()
{
  xWorld = 1.6*m;
  yWorld = 1.6*m;
  zWorld = 3.75*m;
  
  cassetteThickness = 30.345*mm;
  G4double CuThickness = 6.05*mm;
  G4double CuWThickness = 1.4*mm;
  G4double PbThickness = 4.97*mm;
  G4double SiThickness = 0.3*mm;

  nRows = 10;
  nCols = 10;

  xCassette = 1.51*m;
  yCassette = 1.51*m;
  zCassette = cassetteThickness/2.;
  
  xCu = 1.5*m, yCu = 1.5*m, zCu = CuThickness/2.;
  xCuW = 1.5*m, yCuW = 1.5*m, zCuW = CuWThickness/2.;
  xPb = 1.5*m, yPb = 1.5*m, zPb = PbThickness/2.;
  xSi = 1.5*m, ySi = 1.5*m, zSi = SiThickness/2.;
  
  DefineMaterials();
}

HGCalDetector::~HGCalDetector()
{
}

void HGCalDetector::DefineMaterials(){
  
  G4NistManager *nist = G4NistManager::Instance();
  
  worldMat = nist->FindOrBuildMaterial("G4_AIR");
  
  CuW = new G4Material("CuW", 14.979*g/cm3, 2);  
  CuW->AddElement(nist->FindOrBuildElement("Cu"), 25*perCent);
  CuW->AddElement(nist->FindOrBuildElement("W"), 75*perCent);
  
  Cu = new G4Material("Cu", 8.96*g/cm3, 1); 
  Cu->AddElement(nist->FindOrBuildElement("Cu"), 100*perCent);
  
  Pb = new G4Material("Pb", 11.35*g/cm3, 1); 
  Pb->AddElement(nist->FindOrBuildElement("Pb"), 100*perCent);

  Si = new G4Material("Si", 2.33*g/cm3, 1); 
  Si->AddElement(nist->FindOrBuildElement("Si"), 100*perCent);
  
  //Print Info
  // G4cout <<"====== Density of Cu : " << Cu->GetDensity()/(g/cm3) <<" g/cm3 " << G4endl;
  // G4cout <<"====== Radlen of Cu : " << Cu->GetRadlen()/(cm) << " cm" << G4endl;
  // G4cout <<"====== Nucl. Interac. Len of Cu : " << Cu->GetNuclearInterLength()/(cm) << " cm" << G4endl;
  // G4cout <<"===================================================" << G4endl;
  // G4cout <<"====== Density of CuW : " << CuW->GetDensity()/(g/cm3) <<" g/cm3 " << G4endl;
  // G4cout <<"====== Radlen of CuW : " << CuW->GetRadlen()/(cm) << " cm" << G4endl;
  // G4cout <<"====== Nucl. Interac. Len of CuW : " << CuW->GetNuclearInterLength()/(cm) << " cm" << G4endl;
  // G4cout <<"===================================================" << G4endl;
  // G4cout <<"====== Density of Pb : " << Pb->GetDensity()/(g/cm3) <<" g/cm3 " << G4endl;
  // G4cout <<"====== Radlen of Pb : " << Pb->GetRadlen()/(cm) << " cm" << G4endl;
  // G4cout <<"====== Nucl. Interac. Len of Pb : " << Pb->GetNuclearInterLength()/(cm) << " cm" << G4endl;
  // G4cout <<"===================================================" << G4endl;
  // G4cout <<"====== Density of Si : " << Si->GetDensity()/(g/cm3) <<" g/cm3 " << G4endl;
  // G4cout <<"====== Radlen of Si : " << Si->GetRadlen()/(cm) << " cm" << G4endl;
  // G4cout <<"====== Nucl. Interac. Len of Si : " << Si->GetNuclearInterLength()/(cm) << " cm" << G4endl;
}

void HGCalDetector::ConstructCassettes(){
  
  cassetteBox = new G4Box("cassetteBox", xCassette, yCassette, zCassette);
  logicalCassette = new G4LogicalVolume(cassetteBox, worldMat, "logicalCassetteBox");
  
  cuBox = new G4Box("cuBox", xCu, yCu, zCu);
  logicalCu = new G4LogicalVolume(cuBox, Cu, "logicalCuBox");
  
  cuwBox = new G4Box("cuwBox", xCuW, yCuW, zCuW);
  logicalCuW = new G4LogicalVolume(cuwBox, CuW, "logicalCuWBox");
  
  pbBox = new G4Box("pbBox", xPb, yPb, zPb);
  logicalPb = new G4LogicalVolume(pbBox, Pb, "logicalPbBox");
  
  siBox = new G4Box("siBox", xSi/nRows, ySi/nCols, zSi);
  logicalSi = new G4LogicalVolume(siBox, Si, "logicalSiBox");
  
  for(G4int i = 0; i < nRows; i++){
    for(G4int j = 0; j < nCols; j++){
      new G4PVPlacement(0, G4ThreeVector((-xSi + (1+2*i)*xSi/nRows), (-ySi + (1+2*j)*ySi/nCols), -8.0175*mm), logicalSi, "physSi1", logicalCassette, false, j+i*nCols, true);
    }
  }
  new G4PVPlacement(0, G4ThreeVector(0., 0., -6.7725*mm), logicalCuW, "physCuW", logicalCassette, false, 0, true);
  new G4PVPlacement(0, G4ThreeVector(0., 0., -3.0475*mm), logicalCu, "physCu", logicalCassette, false, 0, true);
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0.6775*mm), logicalCuW, "physCuW", logicalCassette, false, 1, true);
  for(G4int i = 0; i < nRows; i++){
    for(G4int j = 0; j < nCols; j++){
      new G4PVPlacement(0, G4ThreeVector((-xSi + (1+2*i)*xSi/nRows), (-ySi + (1+2*j)*ySi/nCols), 1.9225*mm), logicalSi, "physSi2", logicalCassette, false, j+i*nCols, true);
    }
  }
  new G4PVPlacement(0, G4ThreeVector(0., 0., 12.2375*mm), logicalPb, "physPb", logicalCassette, false, 0, true);
  
  G4double airgapThickness = 0.225*mm;
  for(int icas=0;icas<13;icas++){
    G4double zPos = 320*cm + icas*(cassetteThickness + airgapThickness);
    new G4PVPlacement(0, G4ThreeVector(0., 0., zPos), logicalCassette, "Cassette", logicalWorld, false, icas, true);
  }
}

void HGCalDetector::ConstructSDandField()
{
    SensitiveDetector *sensDet = new SensitiveDetector("SensitiveDetector");

    if(logicalSi != NULL)
        logicalSi->SetSensitiveDetector(sensDet);
}

G4VPhysicalVolume *HGCalDetector::Construct()
{
    worldBox = new G4Box("worldBox", xWorld, yWorld, zWorld);
    
    logicalWorld = new G4LogicalVolume(worldBox, worldMat, "logicalWorld");

    physicalWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicalWorld, "physicalWorld", 0, false, 0, true);
    
    ConstructCassettes();

    return physicalWorld;
}
