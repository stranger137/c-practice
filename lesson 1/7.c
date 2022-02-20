#include <stdio.h>

const float PI = 3.14159;

float d(float r) {
    return 2 * r;
}

float p(float r) {
    float ans = PI * r;
    ans = 2 * ans;
    return ans;
}

float s(float r) {
    float ans = PI * r;
    ans = ans * r;
    return ans;
}

int main(){
    float r, dr, pr, sr;
    scanf("%f", &r);
    dr = d(r);
    pr = p(r);
    sr = s(r);
    printf("%f\n%f\n%f\n", dr, pr, sr);
    return 0;
}
