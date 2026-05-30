set terminal pdfcairo
set output "out.scalingB.pdf"

set xlabel "N"
set ylabel "Actual error"

set logscale x
set logscale y

set key top right
set grid

plot \
	"scalingB.data" using 1:2 with linespoints title "LCG actual error", \
	"scalingB.data" using 1:3 with linespoints title "Quasi-random actual error", \
	"scalingB.data" using 1:4 with linespoints title "Quasi estimated error"
