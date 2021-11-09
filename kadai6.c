#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dudt(double u){
    return (u-1) * u;
}
int main(){
    //初期値など
    double dt = 0.04;//刻み幅.変更する.
    double t0 = 0;
    double tn = 100.0;
    double u = 0.5;//u の初期値.変更する.
    int n = (int)tn/dt;
    double t = t0;
    FILE *fp;//ファイルに値を出力
    fp = fopen("kadai6_nasi_05_004.txt", "w");
    fprintf(fp, "%.8f %.8f \n", t, u);

    for(int i=1; i<=n; i++){
        //変数変換せず前進オイラー法で求める.
        t += dt;
        u += dt * dudt(u);
        fprintf(fp, "%.8f %.8f \n", t, u);
    }

    fclose(fp);
}
