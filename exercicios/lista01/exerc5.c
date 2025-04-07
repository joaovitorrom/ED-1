/* 5. Sistema de Cadastro de Funcionários 
Implemente um programa que gerencie um cadastro de funcionários utilizando alocação dinâmica para vetor e ponteiros. Cada funcionário deve possuir um nome, cargo e salário. Crie uma função para criar o vetor dinâmico, uma função para cadastrar cada funcionário por vez e uma função para imprimir os funcionários cadastrados. Além das funções, crie um menu para possibilitar a utilização das funções. */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    char cargo[30];
    float salario;
} Func;

Func* criaVetor(int tam) {
    Func *vetor;

    vetor = (Func*)malloc(sizeof(Func)*tam);
    return vetor;
}

void cadastraFunc(Func *vetor, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        printf("Digite o nome do funcionario: ");
        scanf("%s", &vetor[i].nome);
        printf("Digite o cargo do funcionario: ");
        scanf("%s", &vetor[i].cargo);
        printf("Digite o salario do funcionario: ");
        scanf("%f", &vetor[i].salario);
        printf("\n");
    }
}

void imprimeFunc(Func *vetor, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        printf("\nNome do funcionario: %s", vetor[i].nome);
        printf("\nCargo do funcionario: %s", vetor[i].cargo);
        printf("\nSalario do funcionario: %.2f", vetor[i].salario);
        printf("\n");
    }
}

void menu() {
    printf("=========================================\n");
    printf("            MENU DE CADASTRO\n");
    printf("=========================================\n");
    printf("1 - Cadastrar Funcionario\n");
    printf("2 - Imprimir Funcionarios Cadastrados\n");
    printf("3 - Sair\n");
    printf("===============================\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int tam, opcao;
    Func *vetor;

    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &tam);
    
    vetor = criaVetor(tam);

    do {
        menu();
        scanf("%i", &opcao);
        switch (opcao) {
            case 1:
                cadastraFunc(vetor, tam);
                break;
            case 2:
                imprimeFunc(vetor, tam);
                break;
            default:
                break;
        }
    } while(opcao != 3);

    free(vetor);
    return 0;
}