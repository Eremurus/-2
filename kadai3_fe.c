#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dudt( double u){
    return u;
}

// オイラー法
double solve(double u0, double t0, double tn, int n){
    int i;
    double u, t, dt;
    u = u0;//u の初期値
    t = t0;//t の初期値
    dt = (tn - t0) /n;
    
    // 漸化式を計算
    for ( i=1; i <= n ; i++){
        u += dudt(u) * dt;
        t = t0 + i*dt;
    }
    return u;
}
//実行
int main(){
    double E = 0;
    for(int i=1; i<= 8; i++){
        double u = solve(1, 0, 1, (int)pow(2,i));
        if(i >= 2){//E_rを求められる場合は求める
            printf("%.8f ",fabs(exp(1)-u)/E);
        }
        E = fabs(exp(1)-u);
    }    
}