#include <stdio.h>

int main(){
    int a;
    scanf("%d", &a);
    int b = a;
    int n = 0;
    while(b > 0){
        b = b / 10;
        n++;
    }
    int c = n / 2;
    int i;
    b = a;
    int ten_power = 1;
    for(i = 0; i < c; i++){ten_power = ten_power * 10;}
    if(n % 2 == 0){
        b = b % ten_power;
        a = a / ten_power;
        if(a == b){
            printf("Yes");
        } else {
            printf("No");
        }
    } else {
        printf("No");
    }
    return 0;
}
