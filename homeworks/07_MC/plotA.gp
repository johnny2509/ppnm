set terminal pdfcairo
set output "out.circle.pdf"

set xlabel "N"
set ylabel "Error"

set logscale x
set logscale y

set key top right
set grid

f(x) = a/sqrt(x)
a = 1

fit f(x) "circle.data" using 1:3 via a

plot \
	"circle.data" using 1:3 with linespoints title "estimated error", \
	"circle.data" using 1:4 with linespoints title "actual error", \
	f(x) with lines title sprintf("fit: %.3g/sqrt(N)", a)
