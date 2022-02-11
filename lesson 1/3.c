#include <stdio.h>

int main(){
    int ans = 0;
    int i = 1;
    while(i <= 10) {
        ans += i;
        i += 1;
    }
    printf("%d\n", ans);
    return 0;
}
