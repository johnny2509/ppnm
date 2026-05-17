set terminal pdfcairo enhanced
set output "erf_conv.pdf"

set title "Convergence of erf(1)"
set xlabel "acc"
set ylabel "|erf(1)-exact|"

set logscale xy
set format x "10^{%T}"
set format y "10^{%T}"

set grid
 
plot "erf_acc.dat" using 1:2 with linespoints title "error"
