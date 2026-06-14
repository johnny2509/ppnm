set terminal pngcairo size 900,600 enhanced font "Arial,14"

set output "linear_splineA.png"
set title "Linear spline interpolation of cos(x)"
set xlabel "x"
set ylabel "y"
set key bottom right
set grid

plot \
    "outA.txt" using 1:2 with lines title "cos(x)", \
    "outA.txt" using 1:3 with lines title "linear spline", \
    "pointsA.txt" using 1:2 with points title "tabulated points"


set output "linear_integralA.png"
set title "Integral of linear spline"
set xlabel "x"
set ylabel "Integral"
set key bottom left
set grid

plot \
    "outA.txt" using 1:4 with lines title "exact integral sin(x)", \
    "outA.txt" using 1:5 with lines title "integral of linear spline"
