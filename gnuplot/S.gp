set terminal pdf color enhanced font 'Calibri,16' size 14cm,10cm
set output 'pdf/S.pdf'
set key inside left top font 'Calibri,16'
set xlabel "День" font 'Calibri,16'
set ylabel "Восприимчивые к заражению" font 'Calibri,16'
set format y "%7.f"
plot 'Data/S.txt' using 1:2 title "" w l lw 1.5 lc rgb "red"