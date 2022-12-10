# Characterising Spectral Response of CZT detectors

This directory contains full solution to the tutorial problem on GEANT4 simulation of CZT detectors. The PDF [GEANT4_Workshop2022_CZT_Tutorial](GEANT4_Workshop2022_CZT_Tutorial.pdf) contains the problem statement and expected solutions. The full solution code is given in the Soln1 and Soln2 directory (Two slightly different ways of writing the code.). In the Soln1 directory there are four more folders other than `src` and `include`. They are as follows:

- `mask`: GDML and STL files for coded mask import.
- `rsp`: Response files needed to convolve the input spectrum.
- `python`: Post-processing python codes to analyse root files.
- `plots`: Expected plots for all problems.