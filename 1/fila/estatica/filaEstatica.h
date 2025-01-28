#ifndef FILA_ESTATICA
#define FILA_ESTATICA

const int tamMax = 10;

typedef struct {
    int itens[10];
    int inicio;
    int fim;
} Fila;


void inicializarFila(Fila* f);

int filaVazia(Fila* f); 

int filaCheia(Fila* f); 

void enfileirar(Fila* f, int item);

int desenfileirar(Fila* f); 

void exibirFila(Fila* f); 


#endif