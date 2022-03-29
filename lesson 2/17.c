#include <stdio.h>

int main(){
    int cur_maxi, cur_elem, n;
    int i = 0;
    int cnt = 0;
    int max_cnt = 0;
    scanf("%d", &n);
    scanf("%d", &cur_elem);
    cur_maxi = cur_elem;
    for (i = 1; i < n; i++) {
        scanf("%d", &cur_elem);
        if (cur_elem < cur_maxi) {
            cnt++;
        } else if (cur_elem > cur_maxi) {
            cnt = 0;
            max_cnt = 0;
            cur_maxi = cur_elem;
        } else {
            max_cnt = cnt;
        }
    }
    if (max_cnt == 0) {
        printf("There is only one max element.");
    } else {
        printf("%d", max_cnt);
    }
    return 0;
}
