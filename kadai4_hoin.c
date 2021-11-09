#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dudt( double u){
    double alpha = 10;
    double beta = 1;
    return -alpha * u + beta;
}
//実行
int main(){
    int i;
    double u, t,  k1;
    double u0 = 1;
    double t0=0;
    double tn = 10;
    
    u = u0;
    t = t0;
    double dt = 0.01;//変更する.刻み幅.
    double n = (int)tn/dt;//ステップ数

    FILE *fp;//ファイルに値を出力
    fp = fopen("kadai4_hoin_001.txt", "w");
    fprintf(fp, "%.8f %.8f \n", t, u);
    
    // ホイン法で漸化式を計算
    for ( i=1; i <= n ; i++){
        k1 = dudt(u);
        double u_astalisk = u + k1 * dt;
        u += (k1 + dudt(u_astalisk))*dt/2;
        t += dt;
        fprintf(fp, "%.8f %.8f \n", t, u);
    }
    fclose(fp);

}