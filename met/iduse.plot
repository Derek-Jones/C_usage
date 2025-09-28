#
# iduse.plot, 22 Jun 05

#set terminal postscript eps
set terminal png
set size ratio 0.73
set size 0.7, 0.7
set key off

set border 3
set tics out
set xtics nomirror (1, 200, 400, 600, 800, "1,000" 1000)
set ytics nomirror (1, 10, 100, "1,000" 1000)

set title "Rank/occurrences of global identifier uses"
set xlabel "Rank"
set ylabel "Identifier occurrences"

set logscale y
set pointsize 0.3

set xrange [1:810]
set yrange [1:2000]

plot 'iduse.d' using 0:1 with points
