
#include "ScatPolRunAction.hh"
#include "ScatPolDetectorConstruction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include <iomanip>
//#include <fstream.h>
#include <fstream>

#include "G4SystemOfUnits.hh"

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
}


void ScatPolRunAction::WritePerEvent(evtdata &evt_data)
{
    allEvtData.push_back(evt_data);
}

void ScatPolRunAction::EndOfRunAction(const G4Run* aRun)
{
    file_out=fopen("polarimeter_sim_output.txt","w");
    for (int i=0;i<allEvtData.size();i++)
    {
        //write out scintillator number and energy depositions if only one scintillator has energy deposition
        if((allEvtData[i].scint_index==0)&(allEvtData[i].scint_no!=-1)) 
        {
            fprintf(file_out,"%d\t%lf\t%lf\n",allEvtData[i].scint_no,allEvtData[i].EnePl,allEvtData[i].EneSc);
        }
    }    
    fclose(file_out);

        //fprintf(file_out,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%lf\t%lf\n",allEvtData[i].photPl,allEvtData[i].comptPl,allEvtData[i].raylPl,allEvtData[i].photSc,allEvtData[i].comptSc,allEvtData[i].raylSc,allEvtData[i].scint_no,allEvtData[i].scint_index,allEvtData[i].EnePl,allEvtData[i].EneSc); // to write all details into text file, add this instead in the for loop

}

