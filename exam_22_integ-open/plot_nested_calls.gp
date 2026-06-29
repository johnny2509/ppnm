reset
set terminal pdfcairo enhanced
set output "plot_nested_calls.pdf"

set title "Convergence for integral sqrt(1-x^2) on [0, 1]"
set xlabel "number of calls"
set ylabel "|Q - pi/4|"
set key bottom right

set grid

set logscale xy
set format x "10^{%T}"
set format y "10^{%T}"
set key top right
 
plot "nested_calls_open.dat" using 3:2 with linespoints title "new open 4-point {1/5,2/5,3/5,4/5}", \
    "nested_calls_quad.dat" using 2:3 with linespoints title "old open 4-point, {1/6,2/6,4/6,5/6}"