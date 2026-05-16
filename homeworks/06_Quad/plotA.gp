set terminal pdfcairo
set output "erf_conv.pdf"

set title "Convergence of erf(1)"
set xlabel "acc"
set ylabel "|erf(1)-exact|"

set logscale xy

set grid
 
plot "erf_acc.dat" using 1:2 with linespoints title "error"
