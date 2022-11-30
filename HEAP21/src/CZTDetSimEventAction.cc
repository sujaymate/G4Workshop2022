/**
 *  ********************************************************************
 *  * License and Disclaimer                                           *
 *  *                                                                  *
 *  * The  Geant4 software  is  copyright of the Copyright Holders  of *
 *  * the Geant4 Collaboration.  It is provided  under  the terms  and *
 *  * conditions of the Geant4 Software License,  included in the file *
 *  * LICENSE and available at  http://cern.ch/geant4/license .  These *
 *  * include a list of copyright holders.                             *
 *  *                                                                  *
 *  * Neither the authors of this software system, nor their employing *
 *  * institutes,nor the agencies providing financial support for this *
 *  * work  make  any representation or  warranty, express or implied, *
 *  * regarding  this  software system or assume any liability for its *
 *  * use.  Please see the license in the file  LICENSE  and URL above *
 *  * for the full disclaimer and the limitation of liability.         *
 *  *                                                                  *
 *  * This  code  implementation is the result of  the  scientific and *
 *  * technical work of the GEANT4 collaboration.                      *
 *  * By using,  copying,  modifying or  distributing the software (or *
 *  * any work based  on the software)  you  agree  to acknowledge its *
 *  * use  in  resulting  scientific  publications,  and indicate your *
 *  * acceptance of all terms of the Geant4 Software license.          *
 *  ********************************************************************
 *  
 *  CZTDetSimEventAction.cc
 *  
 */

#include "CZTDetSimEventAction.hh"
#include "CZTDetSimHit.hh"
#include "g4root.hh"
#include "G4SDManager.hh"


CZTDetSimEventAction::CZTDetSimEventAction():HitsCollID(-1)
{

}

//***********************************************/

CZTDetSimEventAction::~CZTDetSimEventAction()
{

}

//***********************************************/

void CZTDetSimEventAction::BeginOfEventAction(const G4Event* event)
{

    /*
    G4int event_id = event->GetEventID();
    G4SDManager* SDman = G4SDManager::GetSDMpointer();
    if(HitsCollID==-1)
    {
        HitsCollID = SDman->GetCollectionID("CZTDetSimHitsCollection");
    }
    */
    G4cout << ">>> Event " << event->GetEventID() << G4endl;
}

//***********************************************/

void CZTDetSimEventAction::EndOfEventAction(const G4Event* event)
{
    G4int event_id = event->GetEventID();
    // Get hits collections of this event
    auto hce = event->GetHCofThisEvent();
    auto fHitsCollection = hce->GetHC(0);
    //CZTDetSimHitCollection* fHitsCollection =0 ;

    std::ofstream t1out("czt1_step_output.txt",std::ios::app);
    std::ofstream t2out("czt1_edep.txt",std::ios::app);

    //if(hce) {
    //if(HitsCollID != -1) fHitsCollection = (CZTDetSimHitCollection*)(hce->GetHC(0));
    //}

    G4int nCZTHits = 0;
    G4double totalEnergyDep_czt =0;

    if(fHitsCollection)
    {
      nCZTHits = fHitsCollection->GetSize();
            G4cout << ">>> Number of hits " << nCZTHits << G4endl;
      for(G4int i=0;i<nCZTHits;i++)
       {

          auto aHit = static_cast<CZTDetSimHit*>(fHitsCollection->GetHit(i));

          G4double HitEnergy_czt = aHit->GetEdep_czt();
          G4int pixPostStep_czt = aHit->GetPixID_post_czt();
          G4double interPosZ_czt = aHit->GetPos_z_czt();
          totalEnergyDep_czt += HitEnergy_czt;


          if((aHit->GetModName_czt())=="czt")

          {
          t1out<<event_id<<"\t"<<pixPostStep_czt<<"\t"<<HitEnergy_czt/keV<<"\t"<<interPosZ_czt/mm <<G4endl;

          }

        }

    t2out<<event_id<<"\t"<<totalEnergyDep_czt/keV<<"\n";

   }

}
