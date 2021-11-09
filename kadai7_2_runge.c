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

int main(){
    double epsilon = 0.01;
    double limit = 100;

    FILE *fp_15;//ファイルに値を出力
    FILE *fp_30;
    FILE *fp_60;
    fp_15 = fopen("kadai7_runge_15.txt", "w");
    fp_30 = fopen("kadai7_runge_30.txt", "w");
    fp_60 = fopen("kadai7_runge_60.txt", "w");       

    //dtの値を変える
    for(int i=0; i<=13; i++){
        //初期値など
        double x = 1 + epsilon;
        double y = 0;
        double z = 0;
        double t = 0;
        double dt = 0.01 * pow(2, -i);
        int n = (int)limit/dt;
        double f1_x,f2_x,f3_x,f4_x,f1_y,f2_y,f3_y,f4_y,f1_z,f2_z,f3_z,f4_z;//仮の変数
        double x_kari,y_kari,z_kari;
        bool recorded_15=false, recorded_30=false, recorded_60=false;//t=15,30,60 で記録されたかどうか

        //ルンゲクッタ法
        for(int k=1; k<=n; k++){

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

            //t=15,30,60 なら出力
            if((int)t == 15 && recorded_15==false){fprintf(fp_15, "%d %.8f \n", i, x); 
                recorded_15=true;
                }
            else if ((int)t==30 && recorded_30==false){ fprintf(fp_30, "%d %.8f \n", i, x); 
                recorded_30=true;
                }
            else if((int)t==60 && recorded_60==false) {fprintf(fp_60, "%d %.8f \n", i, x); 
                recorded_60=true;
            }
        }
    }
    fclose(fp_15);
    fclose(fp_30);
    fclose(fp_60);
}