#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//2次のアダムスバッシュと2次のアダムスムルトンで構成する.
int main(){
    double dt = 0.01;//時間の刻み幅.変更する.
    double t0 = 0;
    double tn = 10;
    double u0 = 1;
    double u = u0;
    int n = (int)tn/dt;//ステップ数
    double t = t0;
    double alpha = 10;
    double beta = 1;
    double f1, f2 = 0;

    FILE *fp;//ファイルに値を出力
    fp = fopen("kadai4_2ji_2ji_001.txt", "w");
    fprintf(fp, "%.8f %.8f \n", t, u);

    for(int i=1; i<=n; i++){
        f1 = -alpha * u + beta;
        t += dt;
        if(i < 2){
            u = (u0-beta/alpha) * exp(-alpha*t) + beta/alpha;
        }
        else{
            double u_tilda = u + (3*f1 - f2 ) * dt/2;
            u += ((-alpha*u_tilda+beta) + f1)*dt/2;
        }
        f2 = f1;
        fprintf(fp, "%.8f %.8f \n", t, u);
    }

    fclose(fp);
}