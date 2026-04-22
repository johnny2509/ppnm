set terminal pngcairo size 900, 600
set output "thx.png"

set title "Radioactive decay of ThX"
set xlabel "t [days]"
set ylabel "activity [y]"

set key top right
set grid

f(x) = a * exp(-lambda * x)
a = 142.404
lambda = 0.170624

plot "thx_fit.dat" using 1:2:3 with yerrorbars title "data", \
	"thx_fit.dat" using 1:4 with lines title "best fit"  
