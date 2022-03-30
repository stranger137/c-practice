#include <stdio.h>

int spaces(char *s, int index) {
    int res = 0;
    int i = index;
    while(s[i] != "\0"){
        if(s[i] == " "){
            res++;
        }
        i++;
    }
    return res;
}

int main(){
    int index, ans, n;
    scanf("%d", &index);
    scanf("%d", &n);
    char s[n];
    fgets(s, n, stdin);
    ans = spaces(s, index);
    printf("%d", n);
    return 0;
}
