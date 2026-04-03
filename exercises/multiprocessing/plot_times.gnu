set title "Running time vs number of threads"
set xlabel "Number of threads"
set ylabel "Time (seconds)"
set grid

plot "out.times" using 1:2 with linespoints lw 2 pt 7 title "runtime"
