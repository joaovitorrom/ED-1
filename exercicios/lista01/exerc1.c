/* 1. Troca de Valores com Ponteiros 
Crie uma função que faça a troca de valores de duas variáveis inteiras usando ponteiros.*/   
#include <stdio.h>
#include <stdlib.h>

void trocaValores (int *p1, int *p2) {
    int aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

int main() {
    int n1, n2;
    n1 = 15;
    n2 = 28;

    trocaValores(&n1, &n2);
    printf("%d , %d", n1, n2);

    return 0;
}