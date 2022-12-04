for ene in 010 020 050 100; do
    echo "Working for energy ${ene}"

cat > gps_unpol.mac << EOF

/gps/particle gamma
/gps/energy $ene keV
/gps/direction 0 0 -1
/gps/pos/centre 0 0 10 cm
/gps/pos/type Plane
/gps/pos/shape Circle
/gps/pos/radius 0.1 mm
/gps/polarization 0.00000 0.0 0.0
/tracking/verbose 0
/run/beamOn 1000000
EOF

./ScatPol gps_unpol.mac > verbose.out

mv sim_output.txt ../results/sim_output_${ene}_UNPOL.txt

done
