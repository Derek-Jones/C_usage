
# multcons.gp, 25 Jun 05
# built on: __DATE

#set terminal postscript eps
set terminal png size 640 480

set origin 0, 0
#set size ratio 0.63
set size 1.4, 0.6

set multiplot

set origin 0, 0
#set size ratio 0.73
set size 0.7, 0.6

#set key off
set key top right reverse Left

set border 3
set tics out
set ytics nomirror (1, 10, 100, "1,000" 1000)
set xtics nomirror (0, 16, 32, 64, 100, 128, 150, 200, 255)

set title "* operator"

set xlabel "Constant value"
set ylabel "integer-constants"

set logscale y
#set pointsize 1.5

set xrange [0:256]
set yrange [0.8:6000]

plot 'multcons.d' using 1:3 pt 2 ps 0.9 title "decimal notation", 'multcons.d' using 1:2 pt 4 ps 0.9 title "hexadecimal notation"

set origin 0.7, 0.0
#set size ratio 0.73
set size 0.6, 0.6

#set key off
set key top right reverse Left

set border 3
set tics out
set ytics nomirror ("" 1, "" 10, "" 100, "" 1000)
set xtics nomirror (0, 16, 32, 64, 100, 128, 150, 200, 255)

set title "/ operator"

set xlabel "Constant value"
set ylabel ""

set logscale y
#set pointsize 1.5

set xrange [0:256]
set yrange [0.8:6000]

plot 'divcons.d' using 1:3 pt 2 ps 0.9 title "", 'multcons.d' using 1:2 pt 4 ps 0.9 title ""

unset multiplot

#pause -1 "blah"

