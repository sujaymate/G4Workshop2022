#!/usr/bin/env python

import argparse
from pathlib import Path

import ROOT
import numpy as np
import matplotlib.pyplot as plt


def plaw(E, nprm, alpha):
    return nprm*E**alpha


parser = argparse.ArgumentParser("Code to generate response matrix from simulations")
parser.add_argument("rootfname", type=str, help="Path to pow-law simulation root file")
parser.add_argument("rspfname", type=str, help="Response file name")
parser.add_argument("--norm", type=int, default=2, help="Power-law norm")
parser.add_argument("--alpha", type=float, default=-1, help="Power-la photon index")
parser.add_argument("--emin", type=float, default=10, help="Min. energy in power-law spec simulation")
parser.add_argument("--emax", type=float, default=210, help="Min. energy in power-law spec simulation")
parser.add_argument("--delT", type=float, default=1000, help="Source duration")
args = parser.parse_args()

rootfname = Path(args.rootfname)
rspfname = Path(args.rspfname)

# load the matrix
rsp = np.load(rspfname.as_posix())

# get the input, output bins and matrix
ebins_in = rsp['ebins_in']
ebins__out = rsp['ebins_out']
rsp_matrix = rsp['matrix']

# input ebin size
dEin = np.diff(ebins_in)[0]

# get input spectra
nE = plaw(ebins_in, args.norm, args.alpha)  # ph/s/cm2/keV

# load the sim data
rootfile = ROOT.TFile(rootfname.as_posix())
EdepTree = rootfile.Get("Edep")

# get total number of events
nEvents = EdepTree.GetEntries()

# initialise events array
events = np.zeros((nEvents, 3))

# fill the events array
for i, entry in enumerate(EdepTree):
    events[i, 0] = entry.eventID
    events[i, 1] = entry.pixID
    events[i, 2] = entry.totalEdep

# select only single pixel events
eventID, index, counts = np.unique(events[:, 0], return_index=True, return_counts=True)

# get single pixel events
single_events = events[index[counts == 1]]

# get the detected counts spectra (cnt / s)
spec_det, bins = np.histogram(single_events[:, 2], bins=ebins__out)
spec_det = spec_det / args.delT
bins = (bins[:-1] + bins[1:]) / 2

# get the expected counts spectra (cnt / s)
spec_det_exp = np.matmul(rsp_matrix.T, nE)*dEin

# plot both the spectra
fig, ax = plt.subplots(1, 1, figsize=(8, 6))
ax.loglog(bins, spec_det, label="Detected")
ax.loglog(bins, spec_det_exp, label="Expected")
ax.legend(fontsize=13)
ax.set_xlabel("Energy (keV)", fontsize=13)
ax.set_ylabel("counts / s", fontsize=13)
fig.savefig("Verify_rsp.png", dpi=150)
plt.show()
