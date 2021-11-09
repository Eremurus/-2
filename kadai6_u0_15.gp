set terminal eps color enhanced
set output "kadai6_u015.eps"
set xlabel "t"
set ylabel "u"
set key 
set arrow from  log(3),0.0 to log(3),100 nohead lw 2 dt (10,5) lc rgb "red"
plot[0:2][0:100]"kadai6_nasi_15_016.txt" title "{変数変換なし{/Symbol D}t =0.16}}" with lines  linewidth 5 ,\
 "kadai6_nasi_15_004.txt" title "{変数変換なし{/Symbol D}t =0.04}}" with lines  linewidth 5,\
 "kadai6_henkan_15_016.txt" title "{変数変換あり{/Symbol D}s =0.16}}" with lines  linewidth 5,\
 "kadai6_henkan_15_004.txt" title "{変数変換あり{/Symbol D}s =0.04}}" with lines  linewidth 5,\

 

