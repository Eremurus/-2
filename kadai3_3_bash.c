#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dudt( double u){
    return u;
}

// 3次のアダムスバッシュ法
double solve(double u0, double t0, double tn, int n){
    int i;
    double u, t, dt, dudt_1, dudt_2, dudt_3;
    
    u = u0;
    t = t0;
    dt = (tn - t0) /n;
    dudt_2 = 0;
    dudt_3 = 0;
    
    // 漸化式を計算
    for ( i=1; i <= n ; i++){
        dudt_1 = dudt(u);
        t += dt;
        if(i < 3){//初期値が揃っていない時は解析解で計算
            u = exp(t);
        }
        else{
            u += dt * (5*dudt_3-16*dudt_2+23*dudt_1)/12.0;
        }
        dudt_3 = dudt_2; dudt_2 = dudt_1;
    }
    return u;
}

int main(){
    double E = 0;
    for(int i=1; i<= 8; i++){
        double u = solve(1, 0, 1, (int)pow(2,i));
        if(i >= 2){
            printf("%.8f ",fabs(exp(1)-u)/E);
        }
        E = fabs(exp(1)-u);
    }    
}