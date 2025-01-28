#ifndef LISTA_H
#define LISTA_H

#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h> // Para a função strcpy

#define MAX_FUNCIONARIOS 100 // Tamanho máximo da lista estática

typedef struct {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int tamanho;
} ListaEstatica;

typedef struct no {
    Funcionario dado;
    struct no *proximo;
} No;


// Funções para a Lista Estática

void inicializaListaEstatica(ListaEstatica *lista) {
    lista->tamanho = 0;
}

int listaEstaticaCheia(ListaEstatica *lista) {
    return lista->tamanho == MAX_FUNCIONARIOS;
}

int insereFuncionarioEstatica(ListaEstatica *lista, Funcionario funcionario) {
    if (listaEstaticaCheia(lista)) {
        return 0; // Inserção falhou
    }
    lista->funcionarios[lista->tamanho] = funcionario;
    lista->tamanho++;
    return 1; // Inserção bem-sucedida
}


// ... outras funções para a lista estática (remover, buscar, listar)

Funcionario buscaFuncionarioEstatica(ListaEstatica *lista, int matricula) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->funcionarios[i].matricula == matricula) {
            return lista->funcionarios[i];
        }
    }
    // Funcionário não encontrado
    Funcionario funcionarioNaoEncontrado;
    // Inicializar os campos da estrutura com valores padrão ou inválidos
    return funcionarioNaoEncontrado;
}

int removeFuncionarioEstatica(ListaEstatica *lista, int matricula) {
    int i, j;

    for (i = 0; i < lista->tamanho; i++) {
        if (lista->funcionarios[i].matricula == matricula) {
            // Encontramos o funcionário a ser removido
            for (j = i; j < lista->tamanho - 1; j++) {
                // Deslocamos todos os elementos após o elemento removido para a esquerda
                lista->funcionarios[j] = lista->funcionarios[j + 1];
            }
            lista->tamanho--;
            return 1; // Remoção bem-sucedida
        }
    }

    return 0; // Funcionário não encontrado
}


#endif
