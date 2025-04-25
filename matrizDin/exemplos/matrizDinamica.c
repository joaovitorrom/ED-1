#include <stdio.h>
#include <stdlib.h>

int main (){
    int **mat, lin = 3, col = 3, i, j;

    mat = (int**)malloc(sizeof(int*)*lin);

    for(i = 0; i < lin; i++) {
        mat[i] = (int*)malloc(sizeof(int*)*col);
    }

    for(i = 0; i < lin; i++) {
        for(j = 0;j < col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for(i = 0; i < lin; i++) {
        for(j = 0; j < col; j++) {
            printf("\nmat[%d][%d] = %d", i, j, mat[i][j]);
        }
    }

    return 0;
}

