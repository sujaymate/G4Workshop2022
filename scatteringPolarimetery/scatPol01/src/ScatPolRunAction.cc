
#include "ScatPolRunAction.hh"
#include "ScatPolDetectorConstruction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include <iomanip>
//#include <fstream.h>
#include <fstream>

#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ScatPolRunAction::ScatPolRunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ScatPolRunAction::~ScatPolRunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ScatPolRunAction::BeginOfRunAction(const G4Run* aRun)
{
	allEvtData.clear();
    file_out=fopen("sim_output.txt","w");
}


void ScatPolRunAction::WritePerEvent(evtdata &evt_data)
{
	allEvtData.push_back(evt_data);
}

void ScatPolRunAction::EndOfRunAction(const G4Run* aRun)
{

  for (int i=0;i<allEvtData.size();i++)
  {
	fprintf(file_out,"%d\t%d\t%lf\t%lf\t%lf\t%lf\n",allEvtData[i].comptFlag,allEvtData[i].raylFlag,allEvtData[i].scatPhotEne,allEvtData[i].scatPhotMomDir[0],allEvtData[i].scatPhotMomDir[1],allEvtData[i].scatPhotMomDir[2]);
  }
  fclose(file_out);

}

