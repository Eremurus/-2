set terminal eps color enhanced
set output "kadai7_1_runge_revise.eps"
set xlabel "x"
set ylabel "y"
set zlabel "z"
set key

splot "kadai7_1_runge.txt" u 1:2:3 title "{x,y,z by Runge-Kutta}"  with lines