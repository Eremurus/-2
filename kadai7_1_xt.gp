set terminal eps color enhanced
set output "kadai7_1_runge_xt_revise.eps"
set xlabel "t"
set ylabel "x"
set key 
plot[0:100] "kadai7_1_runge_xt.txt" title "{x by Runge}" with lines  linewidth 5\
 
