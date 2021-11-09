#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dudt( double u){
    return u;
}

//ホイン法
double solve(double u0, double t0, double tn, int n){
    int i;
    double u, t, dt, k1;
    u = u0;
    t = t0;
    dt = (tn - t0) /n;
    
    // 漸化式を計算
    for ( i=1; i <= n ; i++){
        k1 = dudt(u);
        double u_astalisk = u + k1 * dt;
        u += (k1 + dudt(u_astalisk))*dt/2;
        t += dt;
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