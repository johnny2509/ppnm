set terminal pdfcairo enhanced
set output "erf_plot_open.pdf"

set title "Error Function"
set xlabel "z"
set ylabel "erf(z)"

set grid

plot "erf_plot_open.dat" using 1:2 with lines title "my erf(z)"