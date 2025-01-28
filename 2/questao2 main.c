#include <stdio.h>
#include "lista-dinamica.h"
#include "lista-estatica.h"

int main() {
    ListaEstatica listaEstatica;
    ListaDinamica listaDinamica;
    inicializaListaEstatica(&listaEstatica);
    inicializaListaDinamica(&listaDinamica);

    // Inserir funcionários nas listas
    Funcionario func1 = {"Alice", 1, 3000.0};
    Funcionario func2 = {"Joao", 2, 3500.0};
    Funcionario func3 = {"Maria", 3, 4000.0};

    insereFuncionarioEstatica(&listaEstatica, func1);
    insereFuncionarioEstatica(&listaEstatica, func2);
    insereFuncionarioEstatica(&listaEstatica, func3);

    insereFuncionarioDinamica(&listaDinamica, func1);
    insereFuncionarioDinamica(&listaDinamica, func2);
    insereFuncionarioDinamica(&listaDinamica, func3);

    // Listar todos os funcionários
    printf("Lista Estática:\n");
    listarFuncionariosEstatica(&listaEstatica);

    printf("Lista Dinâmica:\n");
    listarFuncionariosDinamica(&listaDinamica);

    // Buscar um funcionário
    printf("Buscando funcionário com matrícula 2 na lista estática:\n");
    Funcionario buscadoEstatica = buscaFuncionarioEstatica(&listaEstatica, 2);
    if (buscadoEstatica.matricula != 0) {
        printf("Nome: %s, Matrícula: %d, Salário: %.2f\n", buscadoEstatica.nome, buscadoEstatica.matricula, buscadoEstatica.salario);
    } else {
        printf("Funcionário não encontrado.\n");
    }

    printf("Buscando funcionário com matrícula 2 na lista dinâmica:\n");
    Funcionario buscadoDinamica = buscaFuncionarioDinamica(&listaDinamica, 2);
    if (buscadoDinamica.matricula != 0) {
        printf("Nome: %s, Matrícula: %d, Salário: %.2f\n", buscadoDinamica.nome, buscadoDinamica.matricula, buscadoDinamica.salario);
    } else {
        printf("Funcionário não encontrado.\n");
    }

    // Remover um funcionário
    printf("Removendo funcionário com matrícula 1 da lista estática.\n");
    removeFuncionarioEstatica(&listaEstatica, 1);
    listarFuncionariosEstatica(&listaEstatica);

    printf("Removendo funcionário com matrícula 1 da lista dinâmica.\n");
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

    printf("Lista Estática Carregada:\n");
    listarFuncionariosEstatica(&novaListaEstatica);

    printf("Lista Dinâmica Carregada:\n");
    listarFuncionariosDinamica(&novaListaDinamica);

    return 0;
}

