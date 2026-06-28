reset
set terminal pdfcairo enhanced
set output "plot_invsqrt_calls.pdf"

set title "Error vs # of calls for singular integral (1/sqrt(x) on [0, 1])"
set xlabel "# of calls"
set ylabel "Error = |erf(1)-exact|"
set key bottom right

set grid

set logscale y
set xrange [0:100]
set key top right
 
plot "invsqrt_calls_open_cc.dat" using 3:2 with linespoints title "Open nodes {1/5,2/5,3/5,4/5} (Clenshaw-Curtis)", \
    "inv_sqrt_calls_quad.dat" using 2:3 with linespoints title "06 Quad"