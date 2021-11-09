#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//ローレンツ方程式
double dxdt(double x, double y, double z){
    return 10 * (y - x);
}
double dydt(double x, double y, double z){
    return 28*x - y - x*z;
}
double dzdt(double x, double y, double z){
    return x*y - 8*z/3;
}
//実行
int main(){
    double limit = 100;
    double epsilon=0;
    double f1_x,f2_x,f3_x,f4_x,f1_y,f2_y,f3_y,f4_y,f1_z,f2_z,f3_z,f4_z;
    double x=1,y=0,z=0,x_kari,y_kari,z_kari,t=0;
    double dt = 0.01;
    int n = (int)limit/dt;

    FILE *fp_0;//ファイルに値を出力
    fp_0 = fopen("kadai7_1_runge_xt.txt", "w");
    fprintf(fp_0, "%.8f %.8f \n", t,x); 
    //ルンゲクッタ法
    for(int i=1; i<=n; i++){
            t += dt;

            f1_x = dxdt(x,y,z);
            f1_y = dydt(x,y,z);
            f1_z = dzdt(x,y,z);

            f2_x = dxdt(x + f1_x*dt/2,y + f1_y*dt/2,z + f1_z*dt/2);
            f2_y = dydt(x + f1_x*dt/2,y + f1_y*dt/2,z + f1_z*dt/2);
            f2_z = dzdt(x + f1_x*dt/2,y + f1_y*dt/2,z + f1_z*dt/2);

            f3_x = dxdt(x + f2_x*dt/2,y + f2_y*dt/2,z + f2_z*dt/2);
            f3_y = dydt(x + f2_x*dt/2,y + f2_y*dt/2,z + f2_z*dt/2);
            f3_z = dzdt(x + f2_x*dt/2,y + f2_y*dt/2,z + f2_z*dt/2);

            f4_x = dxdt(x + f3_x*dt,y + f3_y*dt,z + f3_z*dt);
            f4_y = dydt(x + f3_x*dt,y + f3_y*dt,z + f3_z*dt);
            f4_z = dzdt(x + f3_x*dt,y + f3_y*dt,z + f3_z*dt);
            
            x_kari = x + (f1_x + 2*f2_x + 2*f3_x + f4_x)*dt/6;
            y_kari = y + (f1_y + 2*f2_y + 2*f3_y + f4_y)*dt/6;
            z_kari = z + (f1_z + 2*f2_z + 2*f3_z + f4_z)*dt/6;

            x = x_kari;
            y = y_kari;
            z = z_kari;
            fprintf(fp_0, "%.8f %.8f \n", t,x); 
    }
    fclose(fp_0);
}