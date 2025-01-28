#include <stdio.h>
#include "filaEstatica.h"


void inicializarFila(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
}

int filaVazia(Fila* f) {
    return f->inicio == f->fim;
}

int filaCheia(Fila* f) {
    return f->fim == tamMax;
}

void enfileirar(Fila* f, int item) {
    if (filaCheia(f)) {
        printf("Fila cheia\n");
    } else {
        f->itens[f->fim] = item;
        f->fim++;
    }
}

int desenfileirar(Fila* f) {
    if (filaVazia(f)) {
        printf("Fila vazia\n");
        return -1;  
    } else {
        int item = f->itens[f->inicio];
        f->inicio++;
        return item;
    }
}

void exibirFila(Fila* f) {
    if (filaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    printf("Fila: ");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->itens[i]);
    }
    printf("\n");
}
