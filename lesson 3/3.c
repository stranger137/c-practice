#include <stdio.h>

int reverse (int a) {
    int res = 0;
    int digit;
    while (a > 0) {
        digit = a % 10;
        res = res * 10 + digit;
        a = a / 10;
    }
    return res;
}

int main() {
    int n, ans;
    scanf("%d", &n);
    ans = reverse(n);
    printf("%d", ans);
    return 0;
}
