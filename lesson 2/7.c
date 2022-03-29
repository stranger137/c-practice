#include <stdio.h>

int main(){
    int a, b, ans;
    scanf("%d %d", &a, &b);
    if (a <= b){
        ans = a;
    } else {
        ans = b;
    }
    while ((ans % a != 0) || (ans % b != 0)){
        ans++;
    }
    printf("%d", ans);
    return 0;
}
