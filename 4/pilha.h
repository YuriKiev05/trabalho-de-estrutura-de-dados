#ifndef ESTRUTURA_PILHA
#define ESTRUTURA_PILHA

const int MAX = 100;

typedef struct {
    int itens[100];
    int topo;
} Pilha;


void inicializarPilha(Pilha* p);

int pilhaVazia(Pilha* p); 

int pilhaCheia(Pilha* p);

void empilhar(Pilha* p, int item);

int desempilhar(Pilha* p); 

int operar(int operando1, int operando2, char operador); 

int avaliarNPI(char* expressao); 

#endif  