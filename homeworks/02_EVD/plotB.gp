set terminal pngcairo size 800, 600

### Plot 1: epsilon vs dr
set output "eps0_vs_dr.png"
set title "Calculated epsilon_0 for fixed rmax=10 and varying dr"
set xlabel "dr"
set ylabel "epsilon_0"
set grid

plot "vary_epsB.dat" using 1:2 with linespoints title "numerically calculated", \
	-0.5 with lines title "exact"

### Plot 2: epsilon vs rmax
set output "eps0_vs_rmax.png"
set title "Calculated epsilon_0 for fixed dr=0.10 and varying rmax"
set xlabel "rmax"
set ylabel "epsilon_0"
set grid
plot "vary_eps2B.dat" using 1:2 with linespoints title "numerically calculated", \
	-0.5 with lines title "exact"
	
