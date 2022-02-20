#include <stdio.h>

int main(){
    int n;
    int flag;
    scanf("%d", &n);
    if ((n / 10000 == n % 10) && ((n / 1000) % 10 == (n % 100) / 10)) {
        flag = 1;
    } else {
        flag = 0;
    }
    printf("%d\n", flag);
    return 0;
}
