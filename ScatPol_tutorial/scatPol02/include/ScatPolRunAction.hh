#ifndef ScatPolRunAction_h
#define ScatPolRunAction_h 1

#include "G4UserRunAction.hh"
#include "G4UserEventAction.hh"
#include "globals.hh"
#include <fstream>
#include <vector>
using namespace std;

class G4Run;

struct evtdata
{

   G4int photPl,comptPl,raylPl;
   G4int photSc,comptSc,raylSc;
   G4int scint_no,scint_index;
   G4double EnePl,EneSc;

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

