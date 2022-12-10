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
 *  CZTDetSimRunAction.cc
 *  
 */

#include "CZTDetSimRunAction.hh"
#include "g4root.hh"

CZTDetSimRunAction::CZTDetSimRunAction()
: G4UserRunAction()
{
}

//***********************************************/

CZTDetSimRunAction::~CZTDetSimRunAction()
{
}

//***********************************************/

void CZTDetSimRunAction::BeginOfRunAction(const G4Run* run)
{
    // Book Edep Ntuple
    auto analysisManager = G4AnalysisManager::Instance();
    G4cout << "Using " << analysisManager->GetType() << G4endl;
    analysisManager->SetVerboseLevel(1);
    G4int runID = run->GetRunID();

    // Define root filename based on runID.
    std::stringstream fname;
    fname << "CZTDetSimRun_" << std::setw(2) << std::setfill('0') << runID;

    analysisManager->SetFileName(fname.str());  // Set root filename
    analysisManager->OpenFile();

    // create the ntuple
    analysisManager->CreateNtuple("Edep", "Energy deposition in CZT");
    analysisManager->CreateNtupleIColumn("eventID");
    analysisManager->CreateNtupleIColumn("pixID");
    analysisManager->CreateNtupleFColumn("totalEdep");
    analysisManager->FinishNtuple(0);
}

//***********************************************/

void CZTDetSimRunAction::EndOfRunAction(const G4Run* run)
{   
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
    delete G4AnalysisManager::Instance();
}