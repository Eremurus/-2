#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dudt( double u){
    return u;
}

//2 次のアダムスバッシュホース法
double solve(double u0, double t0, double tn, int n){
    double u, t, dt, dudt_1, dudt_2;
    
    u = u0;//u の初期値
    t = t0;//t の初期値
    dt = (tn - t0) /n;//刻み幅
    dudt_2 = 0;
    
    // 漸化式を計算
    for (int i=1; i <= n ; i++){
        t += dt;
        dudt_1 = dudt(u);
        if(i < 2){//初期値が足りない時は解析解で計算
            u = exp(t);
        }
        else{
            u += dt * (3*dudt_1 - dudt_2)/2.0;
        }
        dudt_2 = dudt_1;
    }
    return u;
}

//実行
int main(){
    double E = 0;
    for(int i=1; i<= 8; i++){
        double u = solve(1, 0, 1, (int)pow(2,i));
        if(i >= 2){//E_r が定義できる時、計算
            printf("%.8f ",fabs(exp(1)-u)/E);
        }
        E = fabs(exp(1)-u);
    }    
}