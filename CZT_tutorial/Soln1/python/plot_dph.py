#!/usr/bin/env python

import argparse
from pathlib import Path

import ROOT
import numpy as np
import matplotlib.pyplot as plt


parser = argparse.ArgumentParser("Code to plot detector plane histogram")
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
emax = single_events[:, 2].max()

# get pix X and Y index
pixX = np.floor(single_events[:, 1] // 16)
pixY = np.floor(single_events[:, 1] % 16)

# get the histgram and plot
DPH, X, Y = np.histogram2d(pixX, pixY, np.arange(-0.5, 15.6, 1))
fig, ax = plt.subplots(1, 1, figsize=(8, 6))
im = ax.imshow(DPH, origin="lower", cmap="plasma")
ax.set_xticks(np.arange(0, 16, 1))
ax.set_yticks(np.arange(0, 16, 1))
ax.set_xlabel("Pix X", fontsize=13)
ax.set_ylabel("Pix Y", fontsize=13)
plt.colorbar(im)
fig.suptitle("Input energy: {0: 3.0f} keV".format(emax), fontsize=15)
fig.savefig(rootfname.stem + "_DPH_.png", dpi=150)
plt.show()
