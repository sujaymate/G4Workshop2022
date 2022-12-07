#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

# load the full energy deposition file:
a = np.loadtxt("build/electron/czt1_edep.txt")
bins = np.linspace(0, 1000, 128)	# for electrons
#bins = np.linspace(1000,20000,1000)	# for protons

# segregate events from each run : which correspond a single incident energy
da = np.where((np.diff(a[:,0]) < 0))[0];
da = np.append([0],da+1)
da = np.append(da,len(a)-1)
ha = np.zeros([len(da)-1, len(bins)-1])	# histogram of the events for all runs
for i in range(len(da) -1):
    dat = a[da[i]:da[i+1],1];
    ha[i,:] = np.histogram(dat,bins)[0]


    
elec_ene = 100 + np.arange(10)*100		# change this based on the incident energies of electrons given in the simulation
prot_ene = 1000 + np.arange(10)*2000		# change this based on the incident energies of protons given in the simulation

n_total_evt = np.sum(ha,axis=1)
n_norm = 1E4;		# total number of particles given per run in the simulation 
plt.figure()
plt.plot(elec_ene,n_total_evt/n_norm,'*')
plt.xlabel("Incident energy (keV)")
plt.ylabel("Detected fraction");


#plt.figure()
#plt.plot(prot_ene,n_total_evt/n_norm,'*')

plt.figure()
plt.plot(bins[0:-1],ha.T)  
plt.xlabel("Incident energy (keV)");
plt.yalabel("Counts")
