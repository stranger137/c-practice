#include <stdio.h>

int factorial(int x) {
    if (x == 1) {
        printf("factorial(1) = 1\n");
        return x;
    } else {
        printf("factorial(%d) == %d\n", x, x * factorial(x - 1));
        return x * factorial(x - 1);
    }
    return 0;
}

int main(){
    int a, res;
    scanf("%d", &a);
    res = factorial(a);
    printf("%d", res);
    return 0;
}
