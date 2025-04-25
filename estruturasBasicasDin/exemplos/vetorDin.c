#include <stdio.h>
#include <stdlib.h>

// vetor alocado dinamicamente
/*
int main () {
	int *vet, tam;
	printf("Entre com tamanho: ");
	scanf("%d", &tam);
	
	vet = (int*)malloc(sizeof(int)*tam);
	vet[0] = 10;
} 
*/

// vetor alocado dinamicamente de caracteres
int main () {
   	char *vet, tam;
   	int i;
	printf("Entre com tamanho: ");
	scanf("%d", &tam);
	
	vet = (char*)malloc(sizeof(char)*tam);
	
   	for(i = 0; i < tam; i++) {
		printf("Digite uma letra: ");
		scanf("%s", &vet[i]);
	}
	
	printf("Tamanho do vetor: %d", sizeof(vet));
}