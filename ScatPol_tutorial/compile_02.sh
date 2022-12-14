rm -r scatPol02-build
mkdir scatPol02-build
cd scatPol02-build
cmake -DGeant4_DIR=/home/mithun/Bin/geant4/geant4.10.07.p04-install/lib/Geant4-10.7.4 ../scatPol02
make -j8


