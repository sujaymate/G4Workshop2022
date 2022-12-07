

import numpy as np
import matplotlib.pyplot as plt
import time

t1 = time.time()

#a = np.loadtxt("../build/electron_mono/czt1_step_output.txt")
a = np.loadtxt("../build/proton_mono/czt1_step_output.txt")

#bins = np.linspace(20, 2000, 256)  # for electrons
#bins = np.linspace(20, 500, 128)  # for electrons

bins = np.linspace(0,2000,128) # for protons

# segregate events from each run : which correspond a single incident energy
da = np.where((np.diff(a[:,0]) < 0))[0];
da = np.append([0],da+1)
da = np.append(da,len(a))
hist_sing_evts = np.zeros([len(da)-1, len(bins)-1])
hist_split_evts = np.zeros([len(da)-1, len(bins)-1])


all_eve_list = [];
uniq_evts = [];
sing_evts_list =[]; split_evts_list =[];

for i in range(len(da) -1):
    dat = a[da[i]:da[i+1]];
    all_eve_list.append(a[da[i]:da[i+1],:]);
    u_evts, idx_start, count = np.unique(dat[:,0], return_counts=True, return_index=True)

    sing_evts = []; split_evts =[];
    for ind,j in enumerate(u_evts):
        tmp1 = dat[idx_start[ind]:idx_start[ind]+count[ind]]
        tmp2 = [tmp1[0,0],tmp1[0,1],np.sum(tmp1[:,2])]
#        split_evts.append(tmp1) if(len(np.unique(tmp1[:,1])) > 1) else sing_evts.append(tmp1)
        split_evts.append(tmp2) if(len(np.unique(tmp1[:,1])) > 1) else sing_evts.append(tmp2)
    split_evts = np.array(split_evts); sing_evts = np.array(sing_evts);

# Filtering single events and splits events:
    if sing_evts.any():
        hist_sing_evts[i,:] = np.histogram(sing_evts[:,2],bins)[0];
    if split_evts.any():
        hist_split_evts[i,:] = np.histogram(split_evts[:,2],bins)[0]
    sing_evts_list.append(sing_evts); split_evts_list.append(split_evts)
    

t2 = time.time()
print(f"Time taken: {(t2-t1)}s")

#elec_ene = 100 + np.arange(20)*100
prot_ene = 6500 + np.arange(8)*100

n_sing_evt = np.sum(hist_sing_evts,axis=1)
n_split_evt = np.sum(hist_split_evts,axis=1)
n_sum_evt = n_sing_evt + n_split_evt;
n_norm = 1e4 ; # total # of particles given per run
plt.figure()
# for electrons
#plt.plot(elec_ene,n_sing_evt/n_norm,label ="single events fraction")
#plt.plot(elec_ene,n_split_evt/n_norm,label = "split events fraction")
#for protons
#plt.plot(prot_ene,n_sing_evt/n_norm,label ="single events fraction")
#plt.plot(prot_ene,n_split_evt/n_norm,label = "split events fraction")
plt.xlabel("Incident energy (keV)");
plt.ylabel("Detected events/Input particles")
plt.legend(loc="upper right")
plt.title("Single vs Split events: Electrons");
#plt.title("Single vs Split events: Protons");

plt.figure()
plt.plot(bins[0:-1],hist_sing_evts.T)
plt.xlabel("Deposited energy (keV)");
plt.ylabel("Counts")
#plt.title("Single events spectrum: Mono-energy electrons");
plt.title("Single events spectrum: Mono-energy protons");


#plt.figure()
#plt.plot(bins[0:-1],hist_split_evts.T) 
#plt.xlabel("Incident energy (keV)");
#plt.ylabel("Counts")
#plt.title("Split events spectrum");

plt.figure()
plt.plot(bins[0:-1],(hist_sing_evts+hist_split_evts).T) 






#plt.figure()
#plt.plot(prot_ene,n_sing_evt)
#plt.plot(prot_ene,n_split_evt)
