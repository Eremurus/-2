#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double dxdt(double x, double y, double z){
    return 10 * (y - x);
}
double dydt(double y, double x, double z){
    return 28*x - y - x*z;
}
double dzdt(double z, double x, double y){
    return x*y - 8*z/3;
}

int main(){
    double limit = 100;
    double epsilon=0;
    double f1,f2,f3,f4;
    double x=1,y=0,z=0,x_kari,y_kari,z_kari;
    double dt = 0.01, t=0;
    int n = (int)limit/dt;

    FILE *fp_0;//ファイルに値を出力
    fp_0 = fopen("kadai7_1_euler_xt.txt", "w");
    fprintf(fp_0, "%.8f %.8f\n", t,x); 

    for(int i=1; i<=n; i++){
        t += dt;
        x_kari = x +  dt*dxdt(x ,y ,z);
        y_kari = y + dt*dydt(y, x, z);
        z_kari = z + dt*dzdt(z,x,y);
        x = x_kari;
        y = y_kari;
        z = z_kari;
        fprintf(fp_0, "%.8f %.8f \n", t,x);     
    }

    fclose(fp_0);

}