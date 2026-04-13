set terminal pdf
set output "qr_timing.pdf"

set xlabel "N"
set ylabel "time [s]"
set title "Time measurement to QR-factorize an NxN matrix"
set key top left

f(x) = a*x**3
a = 1e-9

fit f(x) "out.times.data" using 1:2 via a

plot "out.times.data" using 1:2 with points title "data", \
	f(x) with lines title sprintf("fit: a*N^3, a = %.3e", a) 
