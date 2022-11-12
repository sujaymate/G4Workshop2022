for ene in 020 025 030 035 040 050 060 070 080 090 100; do
    echo "Working for energy ${ene}"

cat > gps.mac << EOF

/gps/particle gamma
/gps/energy $ene keV
/gps/direction 0 0 -1
/gps/pos/centre 0 0 10 cm
/gps/pos/type Plane
/gps/pos/shape Circle
/gps/pos/radius 0.1 mm
/gps/pos/rot1 0 0 1
/gps/pos/rot2 1 0 0
/gps/polarization 0.00000 0.0 0.0
/tracking/verbose 0
/run/beamOn 1000000
EOF

ScatPol gps.mac > verbose.out

mv sim_output.txt ../results/sim_output_$ene.txt

done
