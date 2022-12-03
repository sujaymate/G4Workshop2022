#!/usr/bin/env python

import argparse
from pathlib import Path

import ROOT
import numpy as np
import matplotlib.pyplot as plt


parser = argparse.ArgumentParser("Code to generate response matrix from simulations")
parser.add_argument("rootfilepath", type=str, help="Path to root files")
parser.add_argument("nphsim", type=int, help="No. of photons ")
parser.add_argument("rspfname", type=str, help=".npz file name to store the rsp matrix")
args = parser.parse_args()

rootfilepath = Path(args.rootfilepath)
nphsim = args.nphsim
rspfname = args.rspfname

# Define input energy array
inp_Energies = np.arange(20, 200.1, 5)

# define the rsp matrix.
dE = 5  # energy bins
ebins_out = np.arange(20. - dE/2, 200. + dE/2 + .1, dE)  # define output bins
mat_rsp = np.zeros((inp_Energies.size, ebins_out.size - 1))

#  loop over root files to get no. of total detections
for i, fname in enumerate(sorted(rootfilepath.glob("*.root"))):
    rootfile = ROOT.TFile(fname.as_posix())

    EdepTree = rootfile.Get("Edep")

    # get total number of events
    nEvents = EdepTree.GetEntries()

    # initialise events array
    events = np.zeros((nEvents, 3))

    # fill the events array
    for j, entry in enumerate(EdepTree):
        events[j, 0] = entry.eventID
        events[j, 1] = entry.pixID
        events[j, 2] = entry.totalEdep

    # select only single pixel events
    eventID, index, counts = np.unique(events[:, 0], return_index=True, return_counts=True)

    # get single pixel events
    single_events = events[index[counts == 1]]

    # store the spectra
    mat_rsp[i, :], bins = np.histogram(single_events[:, 2], bins=ebins_out)

# normalise the matrix by the flux
phflx = nphsim / 3.936**2  # ph /cm2
mat_rsp = mat_rsp / phflx  # cm2 (units of effective area)

# store
np.savez(rspfname, ebins_in=inp_Energies, ebins_out=ebins_out, matrix=mat_rsp)
