set terminal pngcairo size 900,600 enhanced font "Arial,14"

set output "annB.png"
set title "ANN (20 hidden neurons) approximation of g(x)=cos(5x-1)exp(-x^2)"
set xlabel "x"
set ylabel "y"
set grid

plot \
    "outB.txt" using 1:2 with points title "Exact of g(x)", \
    "outB.txt" using 1:3 with points title "ANN approximation of g(x)"

set output "derivativeB.png"
set title "Derivative of ANN (20 hidden neurons) approximation of g(x)=cos(5x-1)exp(-x^2)"
set xlabel "x"
set ylabel "f'_p(x)"
set grid

plot \
    "outB.txt" using 1:4 with points title "Derivative of ANN approximation"

set output "second_derivativeB.png"
set title "Second derivative of ANN (20 hidden neurons) approximation of g(x)=cos(5x-1)exp(-x^2)"
set xlabel "x"
set ylabel "f''_p(x)"
set grid

plot \
    "outB.txt" using 1:5 with points title "Second derivative of ANN approximation"

set output "anti_derivativeB.png"
set title "Anti-derivative of ANN (20 hidden neurons) approximation of g(x)=cos(5x-1)exp(-x^2)"
set xlabel "x"
set ylabel "F_p(x)"
set grid

plot \
    "outB.txt" using 1:6 with points title "Anti-derivative of ANN approximation"