set datafile separator ";"
set grid

set xlabel "U [V]"
set ylabel "T [ns]"

plot "./data/freq_voltage.csv" using 1:2 title "Periodendauer" smooth bezier

set term postscript solid
set output "freq_voltage.ps"
replot