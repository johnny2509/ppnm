set terminal pngcairo size 900,600 enhanced font "Arial,14"

set output "ann.png"
set title "ANN (20 hidden neurons) approximation of g(x)=cos(5x-1)exp(-x^2)"
set xlabel "x"
set ylabel "y"
set grid

plot \
    "outA.txt" using 1:2 with points title "Exact of g(x)", \
    "outA.txt" using 1:3 with points title "ANN approximation of g(x)"