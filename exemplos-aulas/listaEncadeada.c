#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista *prox;
}; 
typedef struct lista Lista;

Lista* inicializa(){
    return NULL;
}

Lista* inserirIni(Lista *l, int v) {
    Lista *novo;
    novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = l;
    return novo;
}

void imprimirLista(Lista *l) {
    while(l != NULL) {
        printf("%d -> ", l->info);
        l = l->prox;
    }
}

Lista* inserirFim(Lista *l, int v) {
    Lista *novo, *aux;
    novo = (Lista*)malloc(sizeof(Lista));
    if(novo != NULL) {
        novo->info = v;
        novo->prox = NULL;
        if(l == NULL) {
            return novo;
        } else {
            aux = l;
            while(aux->prox != NULL) {
                aux = aux->prox;
            }

            aux->prox = novo;
            return l;
        }
    } else {
        printf("\nErro na alocação");
        return l;
    }
}

int main() {
    Lista *l1, *l2, *aux;
    
    l1 = inicializa();
    l1 = inserirIni(l1, 3);
    l1 = inserirIni(l1, 2);
    l1 = inserirIni(l1, 1);
    l1 = inserirFim(l1, 4);

    imprimirLista(l1);
    return 0;
}