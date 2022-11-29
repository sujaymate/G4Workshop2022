#!/usr/bin/env python

import argparse
from pathlib import Path

import ROOT
import numpy as np
import matplotlib.pyplot as plt


parser = argparse.ArgumentParser("Code to plot single pixel spectra")
parser.add_argument("rootfname", type=str, help="Path of root file to open")
args = parser.parse_args()

rootfname = Path(args.rootfname)

# open the root file
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

# plot the spectra
ebins = np.arange(19.5, 200.6, 1)
n, bins = np.histogram(single_events[:, 2], bins=ebins)
bins = (bins[:-1] + bins[1:]) / 2

plt.semilogy(bins, n, ds='steps')
plt.xlabel("Energy (keV)")
plt.ylabel("Counts")
plt.show()
