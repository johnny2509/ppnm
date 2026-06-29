reset
set terminal pdfcairo enhanced
set output "plot_sqrt_calls.pdf"

set title "Convergence for integral sqrt(x) on [0, 1]"
set xlabel "number of calls"
set ylabel "|Q - 2/3|"
set key bottom right

set grid

set logscale xy
set format y "10^{%T}"
set format x "10^{%T}"
set key top right
 
plot "sqrt_calls_open.dat" using 3:2 with linespoints title "new open 4-point {1/5,2/5,3/5,4/5}", \
    "sqrt_calls_quad.dat" using 2:3 with linespoints title "old open 4-point, {1/6,2/6,4/6,5/6}"