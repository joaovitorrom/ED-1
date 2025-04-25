#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

Lista* inicializa() {
    return NULL;
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

Lista* busca(Lista* l, int v) {
    Lista* aux = l;
    while(aux != NULL && aux->info != v) {
        aux = aux->prox;
    }
    return aux;
}

Lista* inserirPosicao3(Lista *l, int v) {
    Lista* aux = l, *novo, *pn, *nos;
    int cont = 1;

    nos = contaNos(l);

    novo = (Lista*)malloc(sizeof(Lista));
    novo -> info = v;
    if(nos > 2) {
        while(aux != NULL && cont < 2) {
            cont++;
            aux = aux->prox;
        }
    } else {
        if (nos == 0) {
            novo->prox = NULL;
            return novo;
        }
        if(nos == 1) {
            novo->prox = NULL;
            l->prox = novo;
            return l;
        }
        if(nos == 2) {
            aux->prox->prox = novo;
            novo->prox = NULL;
            return l;
        }
    }
    pn = aux->prox;
    aux->prox = novo;
    novo->prox = pn;

    return l;
}

int contaNos(Lista *l) {
    int cont = 0;
    while(l!=NULL) {
        cont++;
        l = l->prox;
    }
    return cont;
}

Lista* retirar(Lista *l, int v) {
    Lista *aux = l, *ant = NULL;

    while(aux!=NULL && aux->info!=v) {
        ant = aux;
        aux = aux->prox;
    }

    if(aux==NULL) {
        printf("Elemento nao encontrado!\n");
        return l;
    }

    if(ant==NULL) {
        l = aux->prox; 
    } else {
        ant->prox = aux->prox;
    }

    free(aux);
    return l;
}

void imprimirLista(Lista *l) {
    while(l != NULL) {
        printf("%d -> ", l->info);
        l = l->prox;
    }
}

void imprimirRec(Lista *l) {
    if(l==NULL) {
        return;
    }

    printf("%d -> ", l->info);
    imprimirRec(l->prox);
}

Lista* liberarLista(Lista *l) {
    Lista *aux = l, *r;

    while(aux != NULL) {
        r = aux;
        aux = aux->prox;
        free(r);
    }

    prinf("Lista eliminada!"); 
    return NULL;
}

int main() {
    Lista *l1, *aux, *b;

    l1 = inicializa();
    l1 = inserirFim(l1, 1);
    l1 = inserirFim(l1, 2);
    l1 = inserirFim(l1, 4);
    
    inserirPosicao3(l1, 10);
    imprimirLista(l1);

    /*
    b = busca(l1, 2);
    if(b == NULL) {
        printf("\nNao encontrado");
    } else {
        printf("\nValor do no = %d", b->info);
    }
    */
   printf("\n\n");
    
    l1 = retirar(l1, 8);
    imprimirRec(l1);
    l1 = liberarLista(l1);
    return 0;
}