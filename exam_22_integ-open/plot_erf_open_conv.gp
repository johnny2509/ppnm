set terminal pdfcairo enhanced
set output "erf_plot_open_acc.pdf"

set title "Convergence of erf(1) from the old- and new open 4-point nodes"
set xlabel "acc"
set ylabel "|erf(1)-exact|"
set key bottom right

set logscale xy
set format x "10^{%T}"
set format y "10^{%T}"
set xrange [0.000000006:0.15]

set grid
 
plot "erf_acc_open.dat" using 1:2 with linespoints title "new open 4-point {1/5,2/5,3/5,4/5}", \
    "06_erf_acc.dat" using 1:2 with linespoints title "old open 4-point, {1/6,2/6,4/6,5/6}"