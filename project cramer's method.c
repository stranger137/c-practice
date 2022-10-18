#include <stdio.h>
#include <math.h>
#include <locale.h>

float detf(int n, float m[n][n]) {

       int i, j, k, l, s, z, v, y;

    int nar[n];
    for(i = 0; i < n; i++){
        nar[i] = i;
    }

    i = 0;
    z = 1;
    s = 1;
    v = 0;
    while(z!=n+1){
        s=s*z;
        z++;
    }
    y=s;
    int mas[s][n];

    while(s!=1){
        i = 0;
        z = 1;
        v = 0;
        while(i != n-1){
            if(nar[i] < nar[i+1]){
                v = i;
            }
            i++;
        }
        i = v;

        j = i+1;

        v = i+1;

        while(j < n){
            if(nar[j] > nar[i]){
                v = j;
            }
            j++;
        }
        j = v;

        k = nar[j];
        nar[j]=nar[i];
        nar[i] = k;

        l = 0;
        if(n-i-1>1){

            while(l!=(n-i-1)/2){

                k = nar[n-l-1];
                nar[n-l-1]=nar[i+l+1];
                nar[i+l+1] = k;

                l++;
            }
        }
        l = 0;
        while(l!=n){
            mas[s-2][l]=nar[l];
            l++;
        }
        l = 0;
    s=s-1;
    }

    s = 0;
    l = 0;
    while(l!=n){
        mas[y-1][l]=l;
        l++;
    }

    s=0;
    l=0;

    int det = 0;
    int hdet = 1;
    int inv = 0;
    int o,t;
    s=y-1;
    l=0;
    while(s != -1){
        while(l != n){
            hdet = hdet * m [mas[s][l]][l] ;
            l++;
        }
        inv = 0;
        o = 0;
        t = 0;
        while(t!=n){
            while(o!=n){
                if(mas[s][o]>mas[s][t]){
                    inv++;
                }
                o++;
            }
            t++;
            o = t;
        }

        if(inv%2==0){
            det=det-hdet;
        }
        else{
            det=det+hdet;
        }
        hdet=1;
        l=0;
        s=s-1;
    }

    return det;
}

int main() {

    setlocale(LC_ALL, "Russian"); // Тот код что добавил я

    int i, j, k;
    printf("Enter the scale of matix:\n"); // Тот код что добавил я
    int n;
    scanf("%d", &n);

    //Размер матрицы

    float a[n][n];

    printf("Enter the coefficient matrix of the equation system:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the results of the equation system:\n");
    float b[n];
    for(i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    float detAll = detf(n,a);

    float x[n];  // Массив иксов
    float temp[n][n]; // Временная матрица подстановки
    float detNew; // Определитель

    /*
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < 3; i++){
        printf("%f ", b[i]);
    }
    */

    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(j == k) {
                    temp[i][j] = b[i];
                } else {
                    temp[i][j] = a[i][j];
                }
            }
        }

        detNew = detf(n,temp);
        if(detNew == 0){
            x[k] = 0;
        } else {
            x[k] = detNew/detAll;
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }

    /*
    printf("%f", detAll);
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%f ", a[i][j]);
        }
        printf("\n");
     }
     */

    return 0;
}
