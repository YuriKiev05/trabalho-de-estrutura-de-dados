#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

void inicializarFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int filaVazia(Fila* f) {
    return f->inicio == NULL;
}

void enfileirar(Fila* f, int item) {
    No* novoNo = (No*) malloc(sizeof(No));
    if (!novoNo) {
        printf("erro\n");
        return;
    }
    novoNo->valor = item;
    novoNo->proximo = NULL;

    if (filaVazia(f)) {
        f->inicio = novoNo;
    } else {
        f->fim->proximo = novoNo;
    }
    f->fim = novoNo;
}

int desenfileirar(Fila* f) {
    if (filaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1; 
    }
    No* temp = f->inicio;
    int item = temp->valor;
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    return item;
}

void exibirFila(Fila* f) {
    if (filaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    No* atual = f->inicio;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}