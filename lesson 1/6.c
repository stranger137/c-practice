#include <stdio.h>

int main(){
    int n, digit;
    int ans = 0;
    scanf("%d", &n);
    while(n > 0) {
        digit = n % 10;
        if (digit == 7) {
            ans += 1;
        }
        n = n / 10;
    }
    printf("%d\n", ans);
    return 0;
}
