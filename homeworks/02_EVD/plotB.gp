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

### Plot 3: ground-state and first excited wavefunctions
set output "wavefunc_01.png"
set title "Lowest hydrogen s-wave reduced radial wavefunctions"
set xlabel "r"
set ylabel "f(r)"
set grid
plot "wavefunc_0.dat" using 1:2 with linespoints title "numerical f0(r)", \
	"wavefunc_0.dat" using 1:3 with lines title "analytic n=1", \
	"wavefunc_1.dat" using 1:2 with linespoints title "numerical f1(r)", \
	"wavefunc_1.dat" using 1:3 with lines title "analytic n=2"
