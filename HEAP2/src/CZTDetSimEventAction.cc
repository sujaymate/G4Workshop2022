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

CZTDetSimEventAction::CZTDetSimEventAction()
{

}

//***********************************************/

CZTDetSimEventAction::~CZTDetSimEventAction()
{

}

//***********************************************/

void CZTDetSimEventAction::BeginOfEventAction(const G4Event* event)
{
}

//***********************************************/

void CZTDetSimEventAction::EndOfEventAction(const G4Event* event)
{
    // Get the eventID
    G4int evtID = event->GetEventID();
    
    // Get hits collections of this event
    auto hce = event->GetHCofThisEvent();
    auto aHitsCollection = hce->GetHC(0);
    
    unsigned nHits = aHitsCollection->GetSize();

    // Loop over all pixel hits
    for (unsigned i=0; i<nHits; i++)
    {
        auto aHit = static_cast<CZTDetSimHit*>(aHitsCollection->GetHit(i));
        G4double EdepTotal = aHit->GetEdep();

        // store the edep along with the pixel ID if the value is non-zero
        if (EdepTotal > 0.)
        {
            // call analysis manager
            auto analysisManager = G4AnalysisManager::Instance();
            analysisManager->FillNtupleIColumn(0, 0, evtID);
            analysisManager->FillNtupleIColumn(0, 1, i);
            analysisManager->FillNtupleFColumn(0, 2, EdepTotal);
            analysisManager->AddNtupleRow(0);
        }
    }
}