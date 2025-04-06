/* 4. Impressão Reversa de String Usando Ponteiros 
Crie um programa com uma função que imprima uma string ao contrário usando ponteiros. */
#include <stdio.h>
#include <stdlib.h>

void contrario(char* texto, int tam) {
    int i;

    printf("Digite algo: ");
    for (i = tam; i >= 0; i--)
    {        
        scanf("%c", &texto[i]); 
    }

    printf("\nTexto ao contrario: %s", texto);
}

int main () {
    char *texto;
    int i, tam;

    printf("Defina um tamanho para string: ");
    scanf("%i", &tam);

    texto = (char*)malloc(sizeof(char)*tam);

    contrario(texto, tam);    
    return 0;
}
