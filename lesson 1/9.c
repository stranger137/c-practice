#include <stdio.h>
#include <math.h>

int factorial(int n) {
    int i;
    int ans = 1;
    for (i = 2; i <= n; i++) {
        ans = ans * i;
    }
    return ans;
}

double e(double x){
    double ans = 1;
    int i;
    for (i = 1; i <= 9; i++){
        ans = ans + pow(x, i)/factorial(i);
    }
    return ans;
}

int main(){
    double x, res;
    scanf("%lf", &x);
    res = e(x);
    printf("%lf\n", res);
    return 0;
}

