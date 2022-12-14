rm -r scatPol01a-build
mkdir scatPol01a-build
cd scatPol01a-build
cmake -DGeant4_DIR=/home/mithun/Bin/geant4/geant4.10.07.p04-install/lib/Geant4-10.7.4 ../scatPol01a
make -j8


