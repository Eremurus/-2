#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dudt( double u){
    return u;
}

// オイラー法(初期条件x0,  区間[t0, tn])
double solve(double u0, double t0, double tn, int n){
    int i;
    double u, t, dt;
    u = u0;
    t = t0;
    dt = (tn - t0) /n;
    
    // 漸化式を計算
    for ( i=1; i <= n ; i++){
        u += dxdt(u) * dt;
        t = t0 + i*dt;
    }
    return u;
}

int main(){
    double E = 0;
    for(int i=1; i<= 5; i++){
        double u = eulerMethod(1, 0, 1, (int)pow(2,i));
        if(i >= 2){
            printf("%.8f ",fabs(exp(1)-u)/E);
        }
        E = fabs(exp(1)-u);
    }    
}