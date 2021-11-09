#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //初期値など
    double dt = 0.205;
    double t0 = 0;
    double tn = 10;
    double u = 1;
    int n = (int)tn/dt;
    double t = t0;
    double alpha = 10;
    double beta = 1;

    FILE *fp;//ファイルに値を出力
    fp = fopen("kadai4_krank_0205.txt", "w");
    fprintf(fp, "%.8f %.8f \n", t, u);

    for(int i=1; i<=n; i++){
        u = (beta * dt + u * (1-alpha*dt/2)) / (1 + alpha * dt/2);//クランクニクソン法の線形の漸化式を解いた形
        t += dt;
        fprintf(fp, "%.8f %.8f \n", t, u);
    }

    fclose(fp);
}