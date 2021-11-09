set terminal eps color enhanced
set output "kadai4_yosokusi.eps"
set xlabel "t"
set ylabel "u"
set key 
plot[0:10][-10:10] "kadai4_yosokusi_0205.txt" title "{{/Symbol D}t =0.205}}" with lines  linewidth 5 ,\
 "kadai4_yosokusi_019.txt" title "{{/Symbol D}t =0.19}}" with lines  linewidth 5,\
 "kadai4_yosokusi_001.txt" title "{{/Symbol D}t =0.01}}" with lines  linewidth 5
 

