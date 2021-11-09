#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(){
    double epsilon = 0.01;
    double limit = 100;

    FILE *fp_15;//ファイルに値を出力
    FILE *fp_30;
    FILE *fp_60;
    fp_15 = fopen("kadai7_euler_15.txt", "w");
    fp_30 = fopen("kadai7_euler_30.txt", "w");
    fp_60 = fopen("kadai7_euler_60.txt", "w");       
    //i=0~13 とした時の刻み幅において、t=15,30,60 の時のx を求める.
    for(int i=0; i<=13; i++){
        //初期値
        double x = 1 + epsilon;
        double y = 0;
        double z = 0;
        double t = 0;
        double x_kari,y_kari,z_kari;
        double dt = 0.01 * pow(2, -i);
        int n = (int)limit/dt;
        bool recorded_15=false, recorded_30=false, recorded_60=false;//t=15,30,60 の時のx を記録したかどうか
        
        for(int k=1; k<=n; k++){//前進オイラー法
            t += dt;
            x_kari =  x + (10 * (y - x) * dt);
            y_kari = y + ((28*x - y - x*z) * dt);
            z_kari = z + (x*y - 8*z/3)*dt;
            x = x_kari;
            y = y_kari;
            z = z_kari;
            
            //t=15,30,60の時のx の値を記録.整数に丸めてその値になるt のうち最初のものを抽出.
            if((int)t == 15 && recorded_15==false){ 
                fprintf(fp_15, "%d %.8f \n", i, x); 
                recorded_15=true;
            }
            else if ((int)t == 30 && recorded_30==false){
                fprintf(fp_30, "%d %.8f \n", i, x); 
                recorded_30=true;
            }
            else if((int)t == 60 && recorded_60==false)
                {fprintf(fp_60, "%d %.8f \n", i, x); 
                recorded_60=true;
            }
        }
    }
    fclose(fp_15);
    fclose(fp_30);
    fclose(fp_60);
}