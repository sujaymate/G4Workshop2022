rm -r scatPol01-build
mkdir scatPol01-build
cd scatPol01-build
cmake -DGeant4_DIR=/home/mithun/Bin/geant4/geant4.10.07.p04-install/lib/Geant4-10.7.4 ../scatPol01
make -j8


