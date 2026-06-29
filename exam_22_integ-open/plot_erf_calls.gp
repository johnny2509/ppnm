reset
set terminal pdfcairo enhanced
set output "plot_erf_calls.pdf"

set title "Convergence for erf(1)"
set xlabel "number of calls"
set ylabel "|erf(1)-exact|"
set key bottom right

set grid

set logscale y
set xrange [0:200]
set key top right
 
plot "erf_acc_open.dat" using 3:2 with linespoints title "new open 4-point {1/5,2/5,3/5,4/5}", \
    "erf_calls_quad.dat" using 2:3 with linespoints title "old open 4-point, {1/6,2/6,4/6,5/6}"