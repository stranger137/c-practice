#include <stdio.h>

int main(){
    int n, i, cur;
    int res = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &cur);
        res = res + cur;
    }
    printf("%d", res);
    return 0;
}
