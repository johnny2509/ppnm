set terminal pdfcairo
set output "pendulum.pdf"

set xlabel "t"
set ylabel "theta(t), omega(t)"
set grid
set key top right

plot "pendulum.txt" using 1:2 with lines title "theta(t)", \
	"pendulum.txt" using 1:3 with lines title "omega(t)"	
