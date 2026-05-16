set terminal pdfcairo size 6,6
set output "figC.pdf"

set xlabel "x"
set ylabel "y"
set size ratio -1
set grid
set key top right

plot "outC.txt" using 2:3 with lines lw 3 dt 1 title "body 1", \
	"outC.txt" using 4:5 with lines lw 2 dt 2 title "body 2", \
	"outC.txt" using 6:7 with lines lw 1 dt 3 title "body 3"
