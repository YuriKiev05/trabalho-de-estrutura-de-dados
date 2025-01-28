#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"



void inicializarPilha(Pilha* p) {
    p->topo = -1;
}

int pilhaVazia(Pilha* p) {
    return p->topo == -1;
}


int pilhaCheia(Pilha* p) {
    return p->topo == MAX - 1;
}


void empilhar(Pilha* p, int item) {
    if (!pilhaCheia(p)) {
        p->itens[++(p->topo)] = item;
    } else {
        printf("Pilha cheia\n");
    }
}

int desempilhar(Pilha* p) {
    if (!pilhaVazia(p)) {
        return p->itens[(p->topo)--];
    } else {
        printf("ilha vazia\n");
        return -1;  
    }
}

int operar(int operando1, int operando2, char operador) {
    switch (operador) {
        case '+': return operando1 + operando2;
        case '-': return operando1 - operando2;
        case '*': return operando1 * operando2;
        case '/': return operando1 / operando2;  
        default:
            printf("Operador inválido\n");
            return 0;
    }
}

int avaliarNPI(char* expressao) {
    Pilha pilha;
    inicializarPilha(&pilha);

    char* token = strtok(expressao, " ");
    
    while (token != NULL) {
        if (isdigit(token[0])) {
            empilhar(&pilha, atoi(token));
        } else {
            int operando2 = desempilhar(&pilha);
            int operando1 = desempilhar(&pilha);
            int resultado = operar(operando1, operando2, token[0]);
            empilhar(&pilha, resultado);
        }
        token = strtok(NULL, " ");
    }

   
    return desempilhar(&pilha);
}