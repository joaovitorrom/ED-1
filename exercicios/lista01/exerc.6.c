/* 6. Registro e Manipulação de Produtos 
Implemente um sistema de cadastro de produtos em vetor dinâmico com tamanho escolhido pelo usuário, onde cada produto possui um código, nome e preço. O usuário poderá buscar um produto pelo código e imprimir na tela. O usuário poderá também buscar o produto pelo código e alterar as informações do produto. Crie uma função para imprimir os produtos cadastrados. Crie um menu para possibilitar a utilização das funções.*/
#include <stdio.h>
#include <stdlib.h>

struct {
    int codigo;
    char nome[30];
    float preco;
} typedef Produto;


void cadastraProd(Produto* vetor, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        printf("Digite o codigo do produto: ");
        scanf("%i", &vetor[i].codigo);
        printf("Digite o nome do produto: ");
        scanf("%s", &vetor[i].nome);
        printf("Digite o preco do produto: ");
        scanf("%f", &vetor[i].preco);
        printf("\n");
    }
}

void pesquisaProd(Produto* vetor, int tam) {
    int i, pesquisa, flag;

    printf("Pesquise algum produto pelo codigo: ");
    scanf("%d", &pesquisa);

    for (i = 0; i < tam; i++)
    {
        if(pesquisa == vetor[i].codigo) {
            printf("\nDados do produto pesquisado:");
            printf("\nCodigo do produto: %i", vetor[i].codigo);
            printf("\nNome do produto: %s", vetor[i].nome);
            printf("\nPreco do produto: %.2f", vetor[i].preco);
            flag = 1;
        }
    } 
    if(flag != 1) {
        printf("\nProduto nao encontrado.\n");
    } 
}


alteraProd(Produto* vetor, int tam) {
    int i, pesquisa, flag;

    printf("Pesquise algum produto pelo codigo: ");
    scanf("%d", &pesquisa);

    for (i = 0; i < tam; i++)
    {
        if(pesquisa == vetor[i].codigo) {
            printf("\nDados do produto pesquisado:");
            printf("\nCodigo do produto: %i", vetor[i].codigo);
            printf("\nNome do produto: %s", vetor[i].nome);
            printf("\nPreco do produto: %.2f", vetor[i].preco);
            printf("\n");
            printf("\nAlteracao do produto:\n");
            printf("Novo codigo do produto: ");
            scanf("%i", &vetor[i].codigo);
            printf("Novo nome do produto: ");
            scanf("%s", &vetor[i].nome);
            printf("Novo preco do produto: ");
            scanf("%f", &vetor[i].preco);
            flag = 1;
        }
    } 
    if(flag != 1) {
        printf("\nProduto nao encontrado.\n");
    } 
}

void imprimeProds(Produto* vetor, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        printf("\nCodigo do produto: %i", vetor[i].codigo);
        printf("\nNome do produto: %s", vetor[i].nome);
        printf("\nPreco do produto: %.2f", vetor[i].preco);
        printf("\n");
    }
}

void menu() {
    printf("\n=========================================\n");
    printf("            MENU DE CADASTRO\n");
    printf("=========================================\n");
    printf("1 - Cadastrar Produto\n");
    printf("2 - Pesquisar Produtos Cadastrados\n");
    printf("3 - Alterar Produto\n");
    printf("4 - Imprimir Produtos Cadastrados\n");
    printf("5 - Sair\n");
    printf("===============================\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Produto *vetor;
    int tam, opcao;

    printf("Digite a quantidade de produtos: ");
    scanf("%i", &tam);

    vetor = (Produto*)malloc(sizeof(Produto)*tam);

    do {
        menu();
        scanf("%i", &opcao);
        switch (opcao) {
            case 1:
                cadastraProd(vetor, tam);
                break;
            case 2:
                pesquisaProd(vetor, tam);
                break;
            case 3:
                alteraProd(vetor, tam);
                break;
            case 4:
                imprimeProds(vetor, tam);
                break;
            default:
                break;
        }
    } while(opcao != 5);

    free(vetor);
    return 0;
}