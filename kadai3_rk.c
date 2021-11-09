#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dudt( double u){
    return u;
}

//4次のルンゲクッタ法
double solve(double u0, double t0, double tn, int n){
    int i;
    double u, t, dt;
    u = u0;
    t = t0;
    dt = (tn - t0) /n;
    double f1, f2, f3, f4;
    // 漸化式を計算
    for ( i=1; i <= n ; i++){
        f1 = dudt(u);
        f2 = dudt(u + f1*dt/2);
        f3 = dudt(u + f2*dt/2);
        f4 = dudt(u + f3*dt);
        u += (f1 + 2*f2 + 2*f3 + f4)*dt/6;
        t += dt;
    }
    return u;
}
//実行
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