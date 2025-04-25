/* Fazer um programa que dada uma matriz, apresente a sua transposta. Solicite ao usuário a dimensão da matriz e faça a alocação dinâmica representada por vetor de ponteiros. */
#include <stdio.h>
#include <stdlib.h>

int** criaMatriz(int lin, int col){
    int **mat, i;

    mat = (int**)malloc(sizeof(int*)*lin);

    for(i = 0; i < lin; i++) {
        mat[i] = (int*)malloc(sizeof(int)*col);
    }

    return mat;
}

void transpoeMatriz(int **mat, int lin, int col){
    int i, j;

    for(i = 0; i < lin; i++) {
        for(j = 0; j < col; j++) {
            printf("Insira um elemento na matriz: "); 
            scanf("%d", &mat[i][j]);
        }
    }

    for(i = 0; i < lin; i++) {
        for(j = 0; j < col; j++) {
            printf("\nmat[%d][%d] = %d", i, j, mat[i][j]);
        }
    }

    printf("\n");

    for(j = 0; j < col; j++) {
        for(i = 0; i < lin; i++) {
            printf("\nmatTransposta[%d][%d] = %d", j, i, mat[i][j]);
        }
    }
}

int main() {
    int lin, col;

    printf("Escolha o numero de linhas da matriz: ");
    scanf("%d", &lin);
    printf("Escolha o numero de colunas da matriz: ");
    scanf("%d", &col);

    transpoeMatriz(criaMatriz(lin, col), lin, col);

    return 0;
}