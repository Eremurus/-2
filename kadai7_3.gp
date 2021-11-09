set terminal eps color enhanced
set output "kadai7_3.eps"
set xlabel "t"
set ylabel "x"
set key 
plot[0:30] "kadai7_3_0.txt" title "{{/Symbol e}=0}}" with lines  linewidth 5 ,\
    "kadai7_3_01.txt" title "{{/Symbol e}=0.1}}" with lines  linewidth 5 ,\
    "kadai7_3_001.txt" title "{{/Symbol e}=0.01}}" with lines  linewidth 5 ,\
    "kadai7_3_0001.txt" title "{{/Symbol e}=0.001}}" with lines  linewidth 5
 