#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dudt(double u){//与えられた微分方程式
    return (u-1) * u;
}

int main(){
    //初期値など
    double u0 = 0.5;
    double u = u0;
    double t = 0;
    double sn = 100.0;
    double ds = 0.16; //または0.16
    double s = 0;
    int n = (int)sn/ds;

    FILE *fp;//ファイルに値を出力
    fp = fopen("kadai6_henkan_05_016.txt", "w");
    fprintf(fp, "%.8f %.8f \n", t, u);
    //実行
    for(int i=1; i<=n; i++){
        s += ds;
        //変数変換
        double u_kari = u + ds * (u-1)*u/sqrt(1+pow((u-1),2)*pow(u,2));
        t += ds * 1/sqrt(1+pow(u,2)*pow(u-1,2));
        fprintf(fp, "%.8f %.8f \n", t, u_kari);
        u = u_kari;
    }

    fclose(fp);
}
