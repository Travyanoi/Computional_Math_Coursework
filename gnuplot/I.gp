set terminal pdf color enhanced font 'Calibri,16' size 14cm,10cm
set output 'pdf/I.pdf'
set key inside left top font 'Calibri,16'
set xlabel "День" font 'Calibri,16'
set ylabel "Инфицированные с симптомами" font 'Calibri,16'
plot 'Data/I.txt' using 1:2 title "" w l lw 1.5 lc rgb "red"