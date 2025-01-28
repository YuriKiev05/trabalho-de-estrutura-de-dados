#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

#define MAX_FILA 100

typedef struct {
    Funcionario fila[MAX_FILA];
    int prioridade[MAX_FILA]; // 1: Diretor, 2: Coordenador, 3: Funcionario
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

// Inicializa a fila
void inicializaFila(FilaCircular *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
}

// Verifica se a fila está cheia
int filaCheia(FilaCircular *fila) {
    return fila->tamanho == MAX_FILA;
}

// Verifica se a fila está vazia
int filaVazia(FilaCircular *fila) {
    return fila->tamanho == 0;
}

// Enfileira um funcionário com prioridade
int enfileira(FilaCircular *fila, Funcionario func, int prioridade) {
    if (filaCheia(fila)) {
        return 0; // Fila cheia
    }

    int pos = fila->fim;

    // Inserção com ordenação por prioridade
    while (fila->tamanho > 0 && pos != fila->inicio && fila->prioridade[(pos - 1 + MAX_FILA) % MAX_FILA] > prioridade) {
        fila->fila[pos] = fila->fila[(pos - 1 + MAX_FILA) % MAX_FILA];
        fila->prioridade[pos] = fila->prioridade[(pos - 1 + MAX_FILA) % MAX_FILA];
        pos = (pos - 1 + MAX_FILA) % MAX_FILA;
    }

    fila->fila[pos] = func;
    fila->prioridade[pos] = prioridade;
    fila->fim = (fila->fim + 1) % MAX_FILA;
    fila->tamanho++;
    return 1; // Inserção bem-sucedida
}

// Desenfileira um funcionário
int desenfileira(FilaCircular *fila, Funcionario *func) {
    if (filaVazia(fila)) {
        return 0; // Fila vazia
    }

    *func = fila->fila[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_FILA;
    fila->tamanho--;
    return 1; // Remoção bem-sucedida
}

// Exibe a fila
void exibeFila(FilaCircular *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila de impressão:\n");
    int i = fila->inicio;
    for (int count = 0; count < fila->tamanho; count++) {
        printf("Nome: %s, Matrícula: %d, Prioridade: %d\n",
               fila->fila[i].nome,
               fila->fila[i].matricula,
               fila->prioridade[i]);
        i = (i + 1) % MAX_FILA;
    }
}

int main() {
    FilaCircular fila;
    inicializaFila(&fila);

    Funcionario diretor = {"Diretor A", 1, 10000.0};
    Funcionario coordenador = {"Coordenador B", 2, 7000.0};
    Funcionario funcionario = {"Funcionario C", 3, 4000.0};

    // Enfileirar funcionários com diferentes prioridades
    enfileira(&fila, funcionario, 3);
    enfileira(&fila, diretor, 1);
    enfileira(&fila, coordenador, 2);

    // Exibir fila
    exibeFila(&fila);

    // Desenfileirar e exibir cada elemento
    Funcionario func;
    while (desenfileira(&fila, &func)) {
        printf("Imprimindo: Nome: %s, Matrícula: %d\n", func.nome, func.matricula);
    }

    return 0;
}

