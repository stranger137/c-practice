#include <stdio.h>

int main(){
    int x, y, ans;
    scanf("%d%d", &x, &y);
    ans = x;
    while(y > 1){
        ans *= x;
        y -= 1;
    }
    printf("%d", ans);
    return 0;
}
