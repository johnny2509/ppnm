set terminal pdfcairo enhanced
set output "erf_plot_open.pdf"

set title "Error Function from the new 4-point integrator"
set xlabel "z"
set ylabel "erf(z)"

set grid
set key top left

plot "erf_plot_open.dat" using 1:2 with lines title "erf(z) from 4-point {1/5,2/5,3/5,4/5}"