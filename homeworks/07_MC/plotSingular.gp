set terminal pdfcairo
set output "out.singularB.pdf"

set xlabel "N"
set ylabel "Integral estimate"

set logscale x

set key top right
set grid

plot \
	"singularB.data" using 1:2 with linespoints title "LCG", \
	"singularB.data" using 1:3 with linespoints title "std::mt19937", \
	"singularB.data" using 1:4 with linespoints title "Quasi-random", \
	"singularB.data" using 1:5 with lines title "Exact"
