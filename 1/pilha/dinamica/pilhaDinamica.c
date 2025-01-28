#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

void inicializarPilha(Pilha* p) {
    p->topo = NULL;
}

int pilhaVazia(Pilha* p) {
    return p->topo == NULL;
}

void push(Pilha* p, int item) {
    No* novoNo = (No*) malloc(sizeof(No));  
    if (!novoNo) {
        printf("Erro: Memória insuficiente!\n");
        return;
    }
    novoNo->valor = item;  
    novoNo->proximo = p->topo; 
    p->topo = novoNo;  
}

int pop(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;  
    }
    
    No* temp = p->topo;  
    int item = temp->valor;  
    p->topo = p->topo->proximo;  

    free(temp);  
    return item;  
}

int topo(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;  
    } else {
        return p->topo->valor; 
    }
}

void exibirPilha(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    
    No* atual = p->topo;
    printf("Pilha: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}


void destruirPilha(Pilha* p) {
    No* atual = p->topo;
    No* temp;
    while (atual != NULL) {
        temp = atual;
        atual = atual->proximo;
        free(temp);  
    }
    p->topo = NULL;
}