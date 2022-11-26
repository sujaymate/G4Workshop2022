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
 *  CZTDetSimHit.hh
 *  
 */

#ifndef CZTDETSIMHIT_HH
#define CZTDETSIMHIT_HH

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"

class CZTDetSimHit : public G4VHit
{
    public:
    
        CZTDetSimHit();
        CZTDetSimHit(const CZTDetSimHit&);
        virtual ~CZTDetSimHit();

        // method for memory allocaion
        inline void* operator new(size_t);
        inline void  operator delete(void* hit);

        // methods from base class
        virtual void Draw() {}
        virtual void Print();


};

// Define hits collection
using CZTDetSimHitCollection = G4THitsCollection<CZTDetSimHit>;

// Define allocator to store hits
extern G4ThreadLocal G4Allocator<CZTDetSimHit>* CZTDetSimHitAllocator;

// Define the new and delete allocator operations
inline void* CZTDetSimHit::operator new(size_t)
{
    return (void*)CZTDetSimHitAllocator->MallocSingle();
}

inline void CZTDetSimHit::operator delete(void* hit)
{
    return CZTDetSimHitAllocator->FreeSingle((CZTDetSimHit*)hit);
}

#endif