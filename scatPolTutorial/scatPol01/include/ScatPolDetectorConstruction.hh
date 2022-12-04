
#ifndef ScatPolDetectorConstruction_H
#define ScatPolDetectorConstruction_H 1

class G4LogicalVolume;
class G4VPhysicalVolume;

#include "G4VUserDetectorConstruction.hh"
#include <iostream>
#include <fstream>


class ScatPolDetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    ScatPolDetectorConstruction();
    ~ScatPolDetectorConstruction();

    G4VPhysicalVolume* Construct();
  
};

#endif

