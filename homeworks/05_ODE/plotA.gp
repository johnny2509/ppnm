set terminal pdfcairo
set output "oscillator.pdf"

set xlabel "x"
set ylabel "u(x)"
set grid
set key top right

plot "outA.txt" using 1:2 with lines title "numerical", \
	"outA.txt" using 1:3 with lines title "sin(x)"
