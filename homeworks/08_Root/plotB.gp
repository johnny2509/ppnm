set terminal pngcairo size 900,600 enhanced font "Arial,14"

set output "wavefunctionB.png"
set title "H-atom ground state wavefunction"
set xlabel "r"
set ylabel "f(r)"
set grid

plot \
	"wavefunctionB.txt" using 1:2 with lines title "Numerical", \
	"wavefunctionB.txt" using 1:3 with lines dashtype 2 title "Exact: r exp(-r)"


set output "convergence_rmaxB.txt"
set title "Convergence w.r.t. rmax"
set xlabel "rmax"
set ylabel "|E0+1/2|"
set grid
set logscale y

plot \
	"convergence_rmaxB.txt" using 1:3 with linespoints title "Energy error"

set output "convergence_rminB.txt"
set title "Convergence w.r.t. rmin"
set xlabel "rmin"
set ylabel "|E0+1/2|"
set grid
set logscale x
set logscale y

plot \
        "convergence_rminB.txt" using 1:3 with linespoints title "Energy error"

set output "convergence_accB.txt"
set title "Convergence w.r.t. ODE acc"
set xlabel "acc"
set ylabel "|E0+1/2|"
set grid
set logscale x
set logscale y

plot \
        "convergence_accB.txt" using 1:3 with linespoints title "Energy error"

set output "convergence_epsB.txt"
set title "Convergence w.r.t. ODE eps"
set xlabel "eps" 
set ylabel "|E0+1/2|"
set grid
set logscale x   
set logscale y

plot \
        "convergence_epsB.txt" using 1:3 with linespoints title "Energy error"
