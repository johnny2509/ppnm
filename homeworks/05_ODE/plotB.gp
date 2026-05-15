set terminal pdfcairo size 6,6
set output "orbits.pdf"

set xlabel "x"
set ylabel "y"
set size ratio -1
set grid
set key outside

plot "orbit_circular.txt" using 3:4 with lines title "epsilon=0, u'(0)=0 circular", \
	"orbit_ellipse.txt" using 3:4 with lines title "epsilon=0, u'(0)=-0.5 ellipse", \
	"orbit_precession.txt" using 3:4 with lines title "epsilon=0.01, u'(0)=-0.5 precession"
