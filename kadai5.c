#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dudt(double u){
    return -2 * u + 1;
}

int main(){
    double u2 = 0;
    double u1 = 1;
    double u;
    double dt = 0.1;//刻み幅.
    double t = 0;

    FILE *fp;//ファイルに値を出力
    fp = fopen("kadai5.txt", "w");
    fprintf(fp, "%.8f %.8f \n", t, u1);

    for(int i=1; i<=1000; i++){
        t += dt;
        if(i < 2){
            u = (exp(-2*t) + 1)/2;//初期値が足りない間は解析解を使用
        }
        else{
            u = u2 + 2 * dudt(u1) * dt;
        }
        fprintf(fp, "%.8f %.8f \n", t, u);
        u2 = u1; u1 = u;
    }
    fclose(fp);
}
