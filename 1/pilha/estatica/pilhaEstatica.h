#ifndef PILHA_ESTATICA
#define PILHA_ESTATICA
  

typedef struct {
    int itens[10];
    int topo;
} Pilha;

void inicializarPilha(Pilha* p); 

int pilhaVazia(Pilha* p);

int pilhaCheia(Pilha* p); 

void push(Pilha* p, int item); 

int pop(Pilha* p);

void exibirPilha(Pilha* p);


#endif