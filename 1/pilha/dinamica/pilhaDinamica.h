#ifndef PILHA_DINAMICA
#define PILHA_DINAMICA


typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* topo;
} Pilha;

void inicializarPilha(Pilha* p);

int pilhaVazia(Pilha* p); 

void push(Pilha* p, int item); 

int pop(Pilha* p); 

int topo(Pilha* p);

void exibirPilha(Pilha* p);






#endif