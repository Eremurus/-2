#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//3次のアダムスバッシュと3次のアダムスムルトンで構成する.
int main(){
    double dt = 0.205;//時間の刻み幅.変更する.
    double t0 = 0;
    double tn = 10;
    double u0 = 1;
    double u = u0;
    int n = (int)tn/dt;//ステップ数
    double t = t0;
    double alpha = 10;
    double beta = 1;
    double f1, f2 = 0, f3 = 0;

    FILE *fp;//ファイルに値を出力
    fp = fopen("kadai4_yosokusi_0205.txt", "w");
    fprintf(fp, "%.8f %.8f \n", t, u);

    for(int i=1; i<=n; i++){
        f1 = -alpha * u + beta;
        t += dt;
        if(i < 3){
            u = (u0-beta/alpha) * exp(-alpha*t) + beta/alpha;
        }
        else{
            double u_tilda = u + (23*f1 - 16*f2 + 5*f3) * dt/12;
            u += (5*(-alpha*u_tilda+beta) + 8*f1 - f2)*dt/12;
        }
        f3 = f2; f2 = f1;
        fprintf(fp, "%.8f %.8f \n", t, u);
    }

    fclose(fp);
}