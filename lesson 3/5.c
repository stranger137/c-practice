#include <stdio.h>

double min(double a, double b, double c) {
    double res = a;
    if (b < res) {res = b;}
    if (c < res) {res = c;}
    return res;
}

int main(){
    double x, y, z, ans;
    scanf("%lf %lf %lf", &x, &y, &z);
    ans = min(x, y, z);
    printf("%lf", ans);
    return 0;
}
