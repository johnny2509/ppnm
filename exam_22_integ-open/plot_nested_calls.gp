reset
set terminal pdfcairo enhanced
set output "plot_nested_calls.pdf"

set title "Error as a Function of # of calls (sqrt(1-x^2) on [0, 1])"
set xlabel "# of calls"
set ylabel "Error = |erf(1)-exact|"
set key bottom right

set grid

set logscale y
set xrange [0:100]
set key top right
 
plot "nested_calls_open.dat" using 3:2 with linespoints title "Open nodes {1/5,2/5,3/5,4/5}", \
    "nested_calls_quad.dat" using 2:3 with linespoints title "06 Quad"