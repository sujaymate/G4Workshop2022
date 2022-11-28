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

#include "CZTDetSimSD.hh"
#include "G4Step.hh"
#include "G4VTouchable.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"
#include "G4ThreeVector.hh"

CZTDetSimSD::CZTDetSimSD(const G4String &name,
                         const G4String &hitsCollectionName)
: G4VSensitiveDetector(name),
fHitsCollection(nullptr)
{
    collectionName.insert(hitsCollectionName);
}

//***********************************************/

CZTDetSimSD::~CZTDetSimSD()
{

}

//***********************************************/

void CZTDetSimSD::Initialize(G4HCofThisEvent* hce)
{
    // Create a new hitscollection fot the event
    fHitsCollection = new CZTDetSimHitCollection(SensitiveDetectorName, collectionName[0]);

    // Add this collection to this events hits
    auto hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    hce->AddHitsCollection(hcID, fHitsCollection);

    // Create hits for each pixel
    for (unsigned int i=0; i<256; i++)
    {
        fHitsCollection->insert(new CZTDetSimHit());
    }
}

//***********************************************/

G4bool CZTDetSimSD::ProcessHits(G4Step *aStep, G4TouchableHistory *history)
{
    // Get energy deposit in this step
    G4double edep = aStep->GetTotalEnergyDeposit()/keV;
    G4StepPoint* preStepPoint = aStep->GetPreStepPoint();

    // Define pixel size
    G4double pixelSize = 2.5;  // in mm
    G4double CZTWaferSize = 40.0;  // in mm

    // Exit if edep is zero
    if (edep > 0.)
    {
        // Get energy deposition position
        G4ThreeVector edepPos = preStepPoint->GetPosition();
        G4double edepPosX = edepPos.x()/mm;
        G4double edepPosY = edepPos.y()/mm;

        // Pixellate the detector according the expected scheme
        G4int i = floor((edepPosX + CZTWaferSize/2) / pixelSize);
        G4int j = floor((edepPosY + CZTWaferSize/2) / pixelSize);
        G4int pixID = i + 16*j;

        // Access the hit of this pixel and add the edep
        auto CZThit = (*fHitsCollection)[pixID];
        CZThit->AddEdep(edep);
    }
    return true;
}