#include <stdio.h>

int main(){
    int n, i, cur, prev;
    int cur_cnt = 1;
    int all_cnt = 0;
    scanf("%d", &n);
    scanf("%d", &prev);
    for (i = 1; i < n; i++) {
        scanf("%d", &cur);
        if (prev < cur) {
            cur_cnt++;
        } else {
            if (cur_cnt > 1) {
                all_cnt++;
                printf("Length of the current subsequence: %d\n", cur_cnt);
            }
            cur_cnt = 1;
        }
        prev = cur;
    }
    if (cur_cnt > 1) {
        printf("Length of the current subsequence: %d\n", cur_cnt);
        all_cnt++;
    }
    printf("Total number of subsequences: %d\n", all_cnt);
    return 0;
}
