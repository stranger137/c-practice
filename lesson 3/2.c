#include <stdio.h>

int gcd(int a, int b) {
    int res;
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if (a != 0) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int x, y, res;
    scanf("%d %d", &x, &y);
    res = gcd(x, y);
    printf("%d", res);
    return 0;
}
