#include <stdio.h>
#include "lista-dinamica.h"
#include "lista-estatica.h"

int main() {
    ListaEstatica listaEstatica;
    ListaDinamica listaDinamica;
    inicializaListaEstatica(&listaEstatica);
    inicializaListaDinamica(&listaDinamica);

    // Inserir funcion�rios nas listas
    Funcionario func1 = {"Alice", 1, 3000.0};
    Funcionario func2 = {"Joao", 2, 3500.0};
    Funcionario func3 = {"Maria", 3, 4000.0};

    insereFuncionarioEstatica(&listaEstatica, func1);
    insereFuncionarioEstatica(&listaEstatica, func2);
    insereFuncionarioEstatica(&listaEstatica, func3);

    insereFuncionarioDinamica(&listaDinamica, func1);
    insereFuncionarioDinamica(&listaDinamica, func2);
    insereFuncionarioDinamica(&listaDinamica, func3);

    // Listar todos os funcion�rios
    printf("Lista Est�tica:\n");
    listarFuncionariosEstatica(&listaEstatica);

    printf("Lista Din�mica:\n");
    listarFuncionariosDinamica(&listaDinamica);

    // Buscar um funcion�rio
    printf("Buscando funcion�rio com matr�cula 2 na lista est�tica:\n");
    Funcionario buscadoEstatica = buscaFuncionarioEstatica(&listaEstatica, 2);
    if (buscadoEstatica.matricula != 0) {
        printf("Nome: %s, Matr�cula: %d, Sal�rio: %.2f\n", buscadoEstatica.nome, buscadoEstatica.matricula, buscadoEstatica.salario);
    } else {
        printf("Funcion�rio n�o encontrado.\n");
    }

    printf("Buscando funcion�rio com matr�cula 2 na lista din�mica:\n");
    Funcionario buscadoDinamica = buscaFuncionarioDinamica(&listaDinamica, 2);
    if (buscadoDinamica.matricula != 0) {
        printf("Nome: %s, Matr�cula: %d, Sal�rio: %.2f\n", buscadoDinamica.nome, buscadoDinamica.matricula, buscadoDinamica.salario);
    } else {
        printf("Funcion�rio n�o encontrado.\n");
    }

    // Remover um funcion�rio
    printf("Removendo funcion�rio com matr�cula 1 da lista est�tica.\n");
    removeFuncionarioEstatica(&listaEstatica, 1);
    listarFuncionariosEstatica(&listaEstatica);

    printf("Removendo funcion�rio com matr�cula 1 da lista din�mica.\n");
    removeFuncionarioDinamica(&listaDinamica, 1);
    listarFuncionariosDinamica(&listaDinamica);

    // Salvar as listas em arquivos
    salvarListaEstatica(&listaEstatica, "lista_estatica.csv");
    salvarListaDinamica(&listaDinamica, "lista_dinamica.csv");

    // Carregar as listas de arquivos
    ListaEstatica novaListaEstatica;
    ListaDinamica novaListaDinamica;
    inicializaListaEstatica(&novaListaEstatica);
    inicializaListaDinamica(&novaListaDinamica);

    carregarListaEstatica(&novaListaEstatica, "lista_estatica.csv");
    carregarListaDinamica(&novaListaDinamica, "lista_dinamica.csv");

    printf("Lista Est�tica Carregada:\n");
    listarFuncionariosEstatica(&novaListaEstatica);

    printf("Lista Din�mica Carregada:\n");
    listarFuncionariosDinamica(&novaListaDinamica);

    return 0;
}

