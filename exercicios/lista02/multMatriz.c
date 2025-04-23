/* Fazer um programa que dadas duas matrizes, faça a multiplicação entre elas e apresente o resultado. */
#include <stdio.h>
#include <stdlib.h>

int** criaMatriz(int lin, int col) {
    int **mat, i; 

    mat = (int**)malloc(sizeof(int*)*lin);

    for (i = 0; i < lin; i++) {
        mat[i] = (int*)malloc(sizeof(int)*col);
    }
    
    return mat;
}

void imprimeMatriz(int **mat, int lin, int col) {
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
}

void multMatrizes(int **mat1, int lin1, int col1, int **mat2, int lin2, int col2, int **matMult) {
    int i, j, k;

    if(col1 == lin2) {
        for(i = 0; i < lin1; i++) {
            for(j = 0; j < col2; j++) {
                matMult[i][j] = 0; 
                for(k = 0; k < col1; k++) {
                    matMult[i][j] += mat1[i][k] * mat2[k][j];
                }
                
                printf("\nResultado: mat[%d][%d] = %d", i, j, matMult[i][j]);
            }
        }
    } else {
        printf("\nNao eh possivel fazer a multiplicacao dessas matrizes");
    }
}

int main () {
    int lin1, col1, lin2, col2, **mat1, **mat2, **matMult;

    printf("\nMULTIPLICACAO DE MATRIZES\n");
    printf("Escolha o numero de linhas da matriz 1: ");
    scanf("%d", &lin1);
    printf("Escolha o numero de colunas da matriz 1: ");
    scanf("%d", &col1);
    mat1 = criaMatriz(lin1, col1);
    imprimeMatriz(mat1, lin1, col1);

    printf("\nEscolha o numero de linhas da matriz 2: ");
    scanf("%d", &lin2);
    printf("Escolha o numero de colunas da matriz 2: ");
    scanf("%d", &col2);
    mat2 = criaMatriz(lin2, col2);
    imprimeMatriz(mat2, lin2, col2);

    matMult = criaMatriz(lin1, col2);
    multMatrizes(mat1, lin1, col1, mat2, lin2, col2, matMult);

    return 0;
}
