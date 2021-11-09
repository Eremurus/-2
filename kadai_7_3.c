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

//実行部
int main(){
    double limit = 30;
    double epsilon;
    double f1_x,f2_x,f3_x,f4_x,f1_y,f2_y,f3_y,f4_y,f1_z,f2_z,f3_z,f4_z;
    double x_kari,y_kari,z_kari;
    double dt = pow(0.1, 5);//時間の刻み幅
    int n = (int)limit/dt;//繰り返し回数

    FILE *fp_0;//ファイルに値を出力
    FILE *fp_01;
    FILE *fp_001;
    FILE *fp_0001;
    fp_0 = fopen("kadai7_3_0.txt", "w");
    fp_01 = fopen("kadai7_3_01.txt", "w");
    fp_001 = fopen("kadai7_3_001.txt", "w");
    fp_0001 = fopen("kadai7_3_0001.txt", "w");    

    for(int i=0; i<=3; i++){//epsilon の値を変える
        //初期値
        double t = 0;
        double x;
        double y = 0;
        double z = 0;

        if(i == 0){
            epsilon = 0;
            x = 1 + epsilon;
            fprintf(fp_0, "%.8f %.8f \n", t, x);
        }
        else if(i == 1){
            epsilon = 0.1;
            x = 1 + epsilon;
            fprintf(fp_01, "%.8f %.8f \n", t, x);
        }
        else if(i == 2){
            epsilon = 0.01;
            x = 1 + epsilon;
            fprintf(fp_001, "%.8f %.8f \n", t, x);
        }
        else if(i == 3){
            epsilon = 0.001;
            x = 1 + epsilon;
            fprintf(fp_0001, "%.8f %.8f \n", t, x);
        }

        for(int k=1; k<=n; k++){//ルンゲクッタ法
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

            //epsilon の値に応じて別のファイルに出力
            if(i == 0){fprintf(fp_0, "%.8f %.8f \n", t, x); 
                }
            else if (i == 1){ fprintf(fp_01, "%.8f %.8f \n", t, x); 
                }
            else if(i == 2){fprintf(fp_001, "%.8f %.8f \n", t, x); 
                }
            else if(i == 3){fprintf(fp_0001, "%.8f %.8f \n", t, x); 
                }
            
        }
    }
    fclose(fp_0);
    fclose(fp_01);
    fclose(fp_001);
    fclose(fp_0001);
}
