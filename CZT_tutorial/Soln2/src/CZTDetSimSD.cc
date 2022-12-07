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
 *  CZTDetSimSD.cc
 *  
 */
#include "CZTDetSimHit.hh"
#include "CZTDetSimSD.hh"
#include "G4Step.hh"
#include "G4VTouchable.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"

CZTDetSimSD::CZTDetSimSD(const G4String &name,
                         const G4String &hitsCollectionName)
: G4VSensitiveDetector(name),
fHitsCollection(nullptr)
{
    collectionName.insert(hitsCollectionName);

   // G4String HCname;
   // collectionName.insert(HCname="CZTHitsCollection");
}

//***********************************************/

CZTDetSimSD::~CZTDetSimSD()
{

}

//***********************************************/

void CZTDetSimSD::Initialize(G4HCofThisEvent* hce)
{
    // Create a new hitscollection for the event
    fHitsCollection = new CZTDetSimHitCollection(SensitiveDetectorName, collectionName[0]);

    // Add this collection to this events hits
    auto hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    hce->AddHitsCollection(hcID, fHitsCollection);

    // Create hits
   // fHitsCollection->insert(new CZTDetSimHit());
}

//***********************************************/

G4bool CZTDetSimSD::ProcessHits(G4Step *aStep, G4TouchableHistory *history)
{
    // Get energy deposit in this step
    G4double edep = aStep->GetTotalEnergyDeposit();
    if (edep==0.) return false;

    CZTDetSimHit* newhit = new CZTDetSimHit();
   
   // auto CZThit = (*fHitsCollection)[0];
     //   CZThit->AddEdep(edep);

        if(aStep->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "czt")
         {
            newhit->SetEdep_czt(edep);
            newhit->SetPos_z_czt(aStep->GetPostStepPoint()->GetPosition().z());
            newhit->SetModName_czt(aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName());
            newhit->SetPixID_pre_czt(aStep->GetPreStepPoint()->GetPhysicalVolume()->GetCopyNo());
            newhit->SetPixID_post_czt(aStep->GetPostStepPoint()->GetPhysicalVolume()->GetCopyNo());
         }
     fHitsCollection->insert( newhit );

    return true;
}
