#include <stdio.h>
#include <limits.h>

int main(){
    int cnt = 0;
    int mini = INT_MAX;
    int n, i, cur, prev_cnt;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &cur);
        if(cur < mini) {
            prev_cnt = cnt;
            mini = cur;
        }
        cnt++;
    }
    printf("%d", prev_cnt);
    return 0;
}
