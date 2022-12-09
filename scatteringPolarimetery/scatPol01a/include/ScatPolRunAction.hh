#ifndef ScatPolRunAction_h
#define ScatPolRunAction_h 1

#include "G4UserRunAction.hh"

#include "g4root.hh"
#include "G4Run.hh"

using namespace std;

class G4Run;

class ScatPolRunAction : public G4UserRunAction
{
  public:
    ScatPolRunAction();
   ~ScatPolRunAction();

  public:
    void BeginOfRunAction(const G4Run*);
    void   EndOfRunAction(const G4Run*);

  private:

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

