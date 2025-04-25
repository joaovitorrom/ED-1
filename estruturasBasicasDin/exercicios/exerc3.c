/* 3. Copiar Conteúdo de um Vetor Usando Ponteiros 
Crie um programa com uma função que copie os valores de um vetor de inteiros para outro usando ponteiros. */
#include <stdio.h>
#include <stdlib.h>
#define tam 4

void copiaVetor(int *vet) {
    int i;
    int *vet2;

    vet2 = vet;

    printf(" vetor 2:[ ");
    for(i = 0; i < tam; i++) {
        printf("%d ", vet2[i]);
    } 
    printf("]");
}


int main() {
    int *vet, i;
   
    vet = (int*)malloc(sizeof(int)*tam);

    for(i = 0; i < tam; i++) {
        printf("Preencha o vetor: ");
        scanf("%d", &vet[i]);
    };

    printf("vetor 1:[ ");
    for(i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    } 
    printf("]");

    copiaVetor(vet);
    return 0;
}
