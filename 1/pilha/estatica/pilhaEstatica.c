#include <stdio.h>
#include <stdlib.h>
#include "pilhaEstatica.h"


void inicializarPilha(Pilha* p) {
    p->topo = -1;  
}

int pilhaVazia(Pilha* p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha* p) {
    return p->topo == 10 - 1;
}

void push(Pilha* p, int item) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
    } else {
        p->itens[++(p->topo)] = item;  
    }
}

int pop(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;  
    } else {
        return p->itens[(p->topo)--];  
    }
}

int topo(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;  
    } else {
        return p->itens[p->topo];
    }
}

void exibirPilha(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}