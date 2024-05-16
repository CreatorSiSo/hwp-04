set datafile separator ";"
set grid

set xlabel "U [V]"
set ylabel "I [mA]"

plot "./data/current_voltage.csv" using 1:2 title "Leistungsaufnahme" smooth bezier

# set term png
# set output "current_voltage.png"
# replot

set term postscript solid
set output "current_voltage.ps"
replot