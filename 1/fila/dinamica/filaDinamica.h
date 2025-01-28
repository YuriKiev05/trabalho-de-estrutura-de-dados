#ifndef FILA_DINAMICA
#define FILA_DINAMICA


typedef struct No {
    int valor;
    struct No* proximo;
} No;


typedef struct {
    No* inicio;
    No* fim;
} Fila;



void inicializarFila(Fila* f);

int filaVazia(Fila* f);

void enfileirar(Fila* f, int item);

int desenfileirar(Fila* f); 

void exibirFila(Fila* f); 



#endif