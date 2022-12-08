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

CZTDetSimSD::CZTDetSimSD(const G4String &name,
                         const G4String &hitsCollectionName)
: G4VSensitiveDetector(name)
{
}

//***********************************************/

CZTDetSimSD::~CZTDetSimSD()
{

}

//***********************************************/

void CZTDetSimSD::Initialize(G4HCofThisEvent* hce)
{
    // Create a new hitscollection fot the event

    // Add this collection to this events hits

    // Create hits for each pixel (problem 3 onwards)
}

//***********************************************/

G4bool CZTDetSimSD::ProcessHits(G4Step *aStep, G4TouchableHistory *history)
{
    // Get energy deposit in this step

    // Define pixel size

    // Exit if edep is zero
        
    // Get energy deposition position (Problem 3 onwards)

    // Pixellate the detector according the expected scheme (Problem 3 onwards)

    // Access the hit of this pixel and add the edep (for problem 2 directly add the edep to the hit)
    
    return true;
}