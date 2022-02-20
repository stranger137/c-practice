#include <stdio.h>

int factorial(int n) {
    int i;
    int ans = 1;
    for (i = 2; i <= n; i++) {
        ans = ans * i;
    }
    return ans;
}

int main(){
    int k;
    scanf("%d", &k);
    int p = factorial(k);
    printf("%d\n", p);
    return 0;
}
