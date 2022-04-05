#include <stdio.h>

double *get_answers(double matrix[][], int n, int m){
    double res[n];
    int i, j, cur;
    if (n + 1 == m){
        res[n-1] = matrix[n-1][n] / matrix[n-1][n-1];
        for(i = n-2; i >= 0; i--){
            cur = matrix[i][n];
            for(j = i+1; j < n; j++){
                cur -= res[j] * matrix[i][j];
            }
            res[i] = cur / matrix[i][i];
        }
        return res;
    }
}

int main(){
    double m[3][4] = {{1, 2, 3, 1}, {0, 1, -2, 2}, {0, 0, 1, -1}};
    get_answers(*m, 3, 4);
    double ans[3] = get_answers(*m, 3, 4);
    int i;
    for(i = 0; i < 3; i++){
        printf("%lf ", ans[i]);
    }
    return 0;
}
