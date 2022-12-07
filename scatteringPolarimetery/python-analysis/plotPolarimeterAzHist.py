# plotPolarimeterAzHist.py: Plot azimuthal angle histograms from Geant4 simulation 
# result of a simple ideal X-ray polarimeter in step 2

import glob
import numpy as np
import matplotlib.pyplot as plt
import os

nScint=12

azbins=(np.linspace(0,nScint,nScint+1)-0.5)*(360.0/nScint)

resfiles=sorted(glob.glob('../results/polarimeter_sim_output_020keV_POL*.txt'))


for resf in resfiles:

    fig1, ax1 = plt.subplots()

    fnam=os.path.basename(resf)
    data=np.loadtxt(resf)
    azAng=data[:,0]*360.0/nScint
    ax1.hist(azAng,bins=azbins,histtype='step',label='All events: PA='+fnam[-6:-4],density=True)
    ax1.hist(azAng[(data[:,1]>1.0)],bins=azbins,histtype='step',label='>1keV in Plastic: PA='+fnam[-6:-4],density=True)

    plt.xlabel('Azimuthal Angle (deg)') 
    plt.ylabel('Normalized counts') 
    plt.title('Incident energy: 20 keV')
    plt.legend()
  
    fig1.savefig('figures/polarimeterAzhist_20keV_PA'+fnam[-6:-4])
    #plt.show()
    plt.close()

resfiles=sorted(glob.glob('../results/polarimeter_sim_output_060keV_POL*.txt')) 

for resf in resfiles:

    fig1, ax1 = plt.subplots()

    fnam=os.path.basename(resf)
    data=np.loadtxt(resf)
    azAng=data[:,0]*360.0/nScint
    ax1.hist(azAng,bins=azbins,histtype='step',label='All events: PA='+fnam[-6:-4],density=True)
    ax1.hist(azAng[(data[:,1]>1.0)],bins=azbins,histtype='step',label='>1keV in Plastic: PA='+fnam[-6:-4],density=True)

    plt.xlabel('Azimuthal Angle (deg)')
    plt.ylabel('Normalized counts')
    plt.title('Incident energy: 60 keV')
    plt.legend()

    fig1.savefig('figures/polarimeterAzhist_60keV_PA'+fnam[-6:-4])
    #plt.show()
    plt.close()

 
