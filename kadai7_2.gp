set terminal eps color enhanced
set output "kadai7_2_60_revise.eps"
set xlabel "i"
set ylabel "x"
set key 
plot[0:13] "kadai7_euler_60.txt" title "{Euler method}" with lines  linewidth 5 ,\
 "kadai7_runge_60.txt" title "{Runge-Kutta method}" with lines  linewidth 5\
 

