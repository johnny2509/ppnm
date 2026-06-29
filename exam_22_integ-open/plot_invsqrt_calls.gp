reset
set terminal pdfcairo enhanced
set output "plot_invsqrt_calls.pdf"

set title "Convergance for integral 1/sqrt(x) on [0, 1]"
set xlabel "number of calls"
set ylabel "|Q - 2|"
set key bottom right

set grid

set logscale xy
set format x "10^{%T}"
set format y "10^{%T}"
set key top right
 
plot "invsqrt_calls_open_cc.dat" using 3:2 with linespoints title "new open 4-point {1/5,2/5,3/5,4/5} + CC", \
    "inv_sqrt_calls_quad_cc.dat" using 2:3 with linespoints title "old open 4-point, {1/6,2/6,4/6,5/6} + CC"