#ifndef ScatPolEventAction_h
#define ScatPolEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "ScatPolRunAction.hh"

class ScatPolRunAction;


class ScatPolEventAction : public G4UserEventAction
{
 public:
   ScatPolEventAction();
  ~ScatPolEventAction();

 public:
   void  BeginOfEventAction(const G4Event*);
   void    EndOfEventAction(const G4Event*);
    
   void AddphotPl() {evt_data.photPl+=1;};
   void AddcomptPl() {evt_data.comptPl+=1;};
   void AddraylPl() {evt_data.raylPl+=1;};

   void AddphotSc() {evt_data.photSc+=1;};
   void AddcomptSc() {evt_data.comptSc+=1;};
   void AddraylSc() {evt_data.raylSc+=1;};

   void SetScint(G4int scNo) {if (evt_data.scint_no==scNo||evt_data.scint_no==-1) evt_data.scint_no=scNo; else evt_data.scint_index=1;}; 
   void AddEdepPl(double de){evt_data.EnePl+=de;};
   void AddEdepSc(double de){evt_data.EneSc+=de;};

    
 private:
   ScatPolRunAction*  runAct;
   evtdata evt_data; 
};


#endif

    
