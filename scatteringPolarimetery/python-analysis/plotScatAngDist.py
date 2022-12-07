# plotScatAngDist.py: Plot Energy histogram, scattering angle histograms 
# from the Geant4 simulation results of step 1 

import glob
import numpy as np
import matplotlib.pyplot as plt
import os

# Energy, theta, phi bins for histograms

enebin=np.linspace(0,100,101)
theta=np.linspace(0,np.pi,100)
phi=np.linspace(-np.pi,np.pi,100)

# function to read the text file output written by Geant4 program and 
# compute scattering angles. Note that the format of the file and 
# incident photon direction considered are hard coded
def getScatAngles(resultfile):

    data=np.loadtxt(resultfile)
    comptflag=data[:,0]
    raylflag=data[:,1]
    scatene=data[:,2]
    px=data[:,3]
    py=data[:,4]
    pz=data[:,5]

    scatEneCompt=scatene[comptflag==1]
    scatEneRayl=scatene[raylflag==1]
    
    ## Compute polar scattering angle theta 
    incDir=[0,0,-1]  # incident photon direction in simulation
    scatDir=np.array([px,py,pz])
    scatAngRayl=np.arccos(np.dot(np.transpose(scatDir[:,(raylflag==1)]),incDir))
    scatAngCompt=np.arccos(np.dot(np.transpose(scatDir[:,(comptflag==1)]),incDir))

    ## Compute azimuthal scattering angle phi 
    # Note: xy plane is orthogonal to incident direction in this case.
    # Angles measures from x-axis 

    azAngCompt=np.arctan2(py[comptflag==1],px[comptflag==1])
    azAngRayl=np.arctan2(py[raylflag==1],px[raylflag==1])

    return scatEneCompt,scatEneRayl,scatAngCompt,scatAngRayl,azAngCompt,azAngRayl

resfiles=sorted(glob.glob('../results/sim_output_*POL00.txt'))  # for polarized
#resfiles=sorted(glob.glob('../results/sim_output_*UNPOL.txt')) # for unpolarized


fig1, ax1 = plt.subplots()
fig2, ax2 = plt.subplots()
fig3, ax3 = plt.subplots()
fig4, ax4 = plt.subplots()
fig5, ax5 = plt.subplots()

colors=['C0','C1','C2','C3','C4']

for i,resf in enumerate(resfiles):
    
    fnam=os.path.basename(resf)
    incEne=int(fnam[11:14])

    thetap=np.arange(0,np.pi,0.01)
    ep=incEne/(1+(incEne/511.)*(1-np.cos(thetap)))
    kndsigdtheta=(ep/incEne)**2*((incEne/ep)+(ep/incEne)-np.sin(thetap)**2)*np.sin(thetap)
    
    scatEneCompt,scatEneRayl,scatAngCompt,scatAngRayl,azAngCompt,azAngRayl=getScatAngles(resf)

    #ene histogram/spectra
    ax1.hist(scatEneCompt,bins=enebin,histtype='step',label='Compt '+str(incEne)+' keV')
    ax1.hist(scatEneRayl,bins=enebin,histtype='step',label='Rayl '+str(incEne)+' keV')

    #polar angle distribution for Compton with dsigma/dtheta Differential Cross Section (DCS)

    ax2.hist(scatAngCompt,bins=theta,histtype='step',label='Compt '+str(incEne)+' keV',density=True)
   
    #free electron DCS - KN cross section
    thetap=np.arange(0,np.pi,0.01)
    ep=incEne/(1+(incEne/511.)*(1-np.cos(thetap)))
    kndsigdtheta=(ep/incEne)**2*((incEne/ep)+(ep/incEne)-np.sin(thetap)**2)*np.sin(thetap)
    ax2.plot(thetap,kndsigdtheta/((thetap[1]-thetap[0])*np.sum(kndsigdtheta)),color=colors[i],linestyle='dotted')

    #Compton DCS for carbon
    dcsdata=np.loadtxt('comptonDCS_Carbon_'+fnam[11:14]+'keV.txt')
    dcs_compt=dcsdata[:,1]*np.sin(dcsdata[:,0])
    ax2.plot(dcsdata[:,0],dcs_compt/((dcsdata[1,0]-dcsdata[0,0])*np.sum(dcs_compt)),color=colors[i],linestyle='dashed')


    #polar angle distribution for Rayleigh
    ax3.hist(scatAngRayl,bins=theta,histtype='step',label='Rayl '+str(incEne)+' keV',density=True)
    
    #Azimuthal angle distribution for Compton and Rayleigh
    ax4.hist(azAngCompt,bins=phi,histtype='step',label='Compt '+str(incEne)+' keV',density=True)
    ax5.hist(azAngRayl,bins=phi,histtype='step',label='Rayl '+str(incEne)+' keV',density=True)


ax1.set_xlabel('Energy (keV)')
ax1.set_ylabel('Counts')
ax1.set_xlim([0,100])
ax1.legend()

ax2.plot([0,0],[0,0],linestyle='dotted',color='black',label='KN DCS')
ax2.plot([0,0],[0,0],linestyle='dashed',color='black',label='Carbon DCS')
ax2.set_xlabel('Polar Scattering Angle (radians)')
ax2.set_ylabel('Normalized Counts')
ax2.legend()

ax3.set_xlabel('Polar Scattering Angle (radians)')
ax3.set_ylabel('Normalized Counts')
ax3.legend()

ax4.set_xlabel('Azimuthal Scattering Angle (radians)')
ax4.set_ylabel('Normalized Counts')
ax4.legend()

ax5.set_xlabel('Azimuthal Scattering Angle (radians)')
ax5.set_ylabel('Normalized Counts')
ax5.legend()

figs=[fig1,fig2,fig3,fig4,fig5]
names=['eneHist.png','comptTheta.png','RaylTheta.png','ComptPhi.png','RaylPhi.png']

for i,fig in enumerate(figs):
    #fig.savefig('figures/unpol_'+names[i])
    fig.savefig('figures/pol_'+names[i])

#plt.show()
plt.close()

