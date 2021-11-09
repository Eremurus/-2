set terminal eps color enhanced
set output "kadai5_01.eps"
set xlabel "t"
set ylabel "u"
set key 
plot[0:15][-1000:1000] "kadai5.txt" title "{u}" with lines  linewidth 5

