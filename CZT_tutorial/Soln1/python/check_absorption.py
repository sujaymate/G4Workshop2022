#!/usr/bin/env python

import argparse
from pathlib import Path

import ROOT
import numpy as np
import matplotlib.pyplot as plt


parser = argparse.ArgumentParser("Code to check absorption of CZT detector")
parser.add_argument("rootfilePath", type=str, help="Path to root files.")
parser.add_argument("nist_data_fname", type=str, help="Text file CZT absorption coefficients")
parser.add_argument("nphsim", type=int, help="No. of input photons simulated")
args = parser.parse_args()

rootfilePath = Path(args.rootfilePath)
nist_data_fname = args.nist_data_fname
nphsim = args.nphsim

# Define input energy array
inp_Energies = np.arange(20, 200.1, 10)

# Initialise detection array to store  no. of detections at each energy
nDet = np.zeros((inp_Energies.size,))

# loop over root files to get no. of total detections
for i, fname in enumerate(sorted(rootfilePath.glob("*.root"))):
    rootfile = ROOT.TFile(fname.as_posix())
    EdepTree = rootfile.Get("Edep")
    nDet[i] = EdepTree.GetEntries()

# compute the expected absorption efficiency
nist_data = np.loadtxt(nist_data_fname)  # load the NIST corss-sections
nist_data[:, 0] = nist_data[:, 0]*1000  # convet MeV to keV

# compute absoption efficiency from scattering cross secion and simulation
eff_nist = 1 - np.exp(-nist_data[:, 1]*5.78*0.5)  # 5.78 g/cc CZT density, 0.5 cm thickness
eff_g4 = nDet/nphsim

# plot both efficiencies
plt.plot(inp_Energies, eff_g4, 'o', label="GEANT4")
plt.plot(nist_data[:, 0], eff_nist, 'o', label="NIST")
plt.xlabel("Energy (keV)")
plt.ylabel("Efficiency")
plt.legend()
plt.savefig("CZT_photon_efficiency_vs_energy.png")
plt.show()
