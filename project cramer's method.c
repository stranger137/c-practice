#include <stdio.h>
#include <math.h>

float det(float m[3][3]) {
    float ans = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) + m[0][1] * (m[1][2] * m[2][0] - m[1][0] * m[2][2]) + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    return ans;
}

int main() {
    int i, j, k;
    float a[3][3];

    printf("Enter the coefficient matrix of the equation system:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the results of the equation system:\n");
    float b[3];
    for(i = 0; i < 3; i++) {
        scanf("%f", &b[i]);
    }

    float detAll = det(a);

    float x[3];
    float temp[3][3];
    float detNew;

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

    for(k = 0; k < 3; k++) {
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                if(j == k) {
                    temp[i][j] = b[i];
                } else {
                    temp[i][j] = a[i][j];
                }
            }
        }

        detNew = det(temp);
        if(detNew == 0){
            x[k] = 0;
        } else {
            x[k] = detNew/detAll;
        }
    }

    for(int i = 0; i < 3; i++) {
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
