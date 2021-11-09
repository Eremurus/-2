set terminal eps color enhanced
set output "kadai4_2ji_2ji.eps"
set xlabel "t"
set ylabel "u"
set key 
plot[0:10][-10:10] "kadai4_2ji_2ji_0205.txt" title "{{/Symbol D}t =0.205}}" with lines  linewidth 5 ,\
 "kadai4_2ji_2ji_019.txt" title "{{/Symbol D}t =0.19}}" with lines  linewidth 5,\
 "kadai4_2ji_2ji_001.txt" title "{{/Symbol D}t =0.01}}" with lines  linewidth 5,\
 0.9*exp(-10*x)+1/10 title "{exact}" with lines  linewidth 5
 