#ifndef ScatPolRunAction_h
#define ScatPolRunAction_h 1

#include "G4UserRunAction.hh"
#include "G4UserEventAction.hh"
#include "globals.hh"
//#include <iostream>
#include <fstream>

#include "G4ThreeVector.hh"


#include <vector>

using namespace std;

class G4Run;

struct evtdata
{
    G4int comptFlag;
    G4int raylFlag;
    G4ThreeVector scatPhotMomDir;
    G4double scatPhotEne;
};

class ScatPolRunAction : public G4UserRunAction
{
  public:
    ScatPolRunAction();
   ~ScatPolRunAction();

  public:
    void BeginOfRunAction(const G4Run*);
    void   EndOfRunAction(const G4Run*);

    void WritePerEvent(evtdata &evt_data);

  private:

   FILE* file_out;
   vector <evtdata> allEvtData;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

