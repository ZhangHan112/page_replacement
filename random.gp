reset
set term png enhanced font 'Helvetica,10' size '600,960'
set output "Random.png"
set xlabel "Frame Size" font "Helvetica,12"
set ylabel "Page Faults" font "Helvetica ,12" offset 1,0
set title "Random" font "Helvetica,16"
set grid
set xtics 0 ,10 ,100
set ytics offset -1,0
set key box

plot \
"FIFO.dat" using 1:2 with linespoints lw 2 lc 2 pt 7 title "FIFO",\
''          using 1:2:2 with labels center offset 1.1,0.8 notitle,\
"Optimal.dat" using 1:2 with linespoints lw 2 lc 6 pt 7 title "Optimal",\
''          using 1:2:2 with labels center offset 1.1,0.8 notitle,\
"My_Algo.dat" using 1:2 with linespoints lw 2 lc 5 pt 7 title "My Algo",\
''          using 1:2:2 with labels center offset 1.1,-0.8 notitle,\