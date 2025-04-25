/* 2. Alocação Dinâmica de Vetor 
Crie um programa com uma função que crie um vetor dinamicamente de números inteiros com tamanho definido pelo usuário. Também deve ter outra função para que o usuário possa preencher os valores e outra função que imprima os valores preenchidos. Apresente na função main a utilização de todas as funcionalidades. */
#include <stdio.h>
#include <stdlib.h>

int* criaVetor(int tam) {
    int *vet;
    vet = (int*)malloc(sizeof(int)*tam);
    return vet;
};

void preencheVetor (int *vet, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        printf("Preencha o vetor: ");
        scanf("%d", &vet[i]);
    } 
}

void imprimeVetor(int *vet, int tam) {
    int i;

    printf("[ ");
    for(i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    } 
    printf("]");
}

int main() {
    int tam, *vet;
    printf("Defina um tamanho para o vetor: ");
    scanf("%d", &tam);

    vet = criaVetor(tam);
    preencheVetor(vet, tam);
    imprimeVetor(vet, tam);
    return 0;
}