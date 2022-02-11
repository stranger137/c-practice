#include <stdio.h>

int main() {
    double ans = 0;
    int cur;
    int i;
    for (i = 1; i <= 5; i++) {
        scanf("%d", &cur);
        ans += cur;
    }
    ans = ans / 5.0;
    printf("%.1f\n", ans);
    return 0;
}
