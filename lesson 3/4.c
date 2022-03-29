#include <stdio.h>
#include <math.h>

int prime(int n) {
    int i;
    for (i = 2; i < round(sqrt(n)); i++) {
        if (n % i == 0) {return 0;}
    }
    return 1;
}

int main() {
    int a, flag;
    scanf("%d", &a);
    flag = prime(a);
    if (flag == 1) {
        printf("The number is prime.");
    } else {
        printf("The number is composite.");
    }
    return 0;
}
