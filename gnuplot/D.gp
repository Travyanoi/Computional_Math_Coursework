set terminal pdf color enhanced font 'Calibri,16' size 14cm,10cm
set output 'pdf/D.pdf'
set key inside left top font 'Calibri,16'
set xlabel "День" font 'Calibri,16'
set ylabel "Количество погибших" font 'Calibri,16'
plot 'Data/D.txt' using 1:2 title "" w l lw 1.5 lc rgb "red"