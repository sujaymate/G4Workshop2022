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
 *  CZTDetSimHit.cc
 *  
 */

#include "CZTDetSimHit.hh"

// Define the allocator
G4ThreadLocal G4Allocator<CZTDetSimHit>* CZTDetSimHitAllocator = 0;

CZTDetSimHit::CZTDetSimHit()
: G4VHit()

{

    edep_czt=0.0;
    pos_z_czt = 0.0;
    pix_id_pre_czt = 0.0;
    pix_id_post_czt = 0.0;
    fTotalEdep = 0.0;
}

//***********************************************/

CZTDetSimHit::~CZTDetSimHit()
{}

//***********************************************/

CZTDetSimHit::CZTDetSimHit(const CZTDetSimHit& right)
: G4VHit()
{
    edep_czt      = right.edep_czt;
    pos_z_czt     = right.pos_z_czt;
    mod_name_czt  = right.mod_name_czt;
    pix_id_pre_czt    = right.pix_id_pre_czt;
    pix_id_post_czt    = right.pix_id_post_czt;
    fTotalEdep = right.fTotalEdep;
}

//***********************************************/

const CZTDetSimHit& CZTDetSimHit::operator=(const CZTDetSimHit& right)
{
    edep_czt      = right.edep_czt;
    pos_z_czt     = right.pos_z_czt;
    mod_name_czt  = right.mod_name_czt;
    pix_id_pre_czt    = right.pix_id_pre_czt;
    pix_id_post_czt    = right.pix_id_post_czt;

    return *this;
}

//***********************************************/

G4int CZTDetSimHit::operator==(const CZTDetSimHit& right) const
{
    return ( this == &right ) ? 1 : 0;
}

//***********************************************/

void CZTDetSimHit::Print()
{

}

//***********************************************/

void CZTDetSimHit::AddEdep(G4double edep)
{
    fTotalEdep += edep;
}

//***********************************************/

G4double CZTDetSimHit::GetEdep() const
{
    return fTotalEdep;
}
