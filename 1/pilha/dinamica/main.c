#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.c"
#include "pilhaDinamica.h"




int main() {
    Pilha p;
    inicializarPilha(&p);
    int tamInicial = 0;

    printf("pilha inicializada. Quantos itens deseja adicionar?:");
    scanf("%d", &tamInicial);

    for(int i = 0; i<tamInicial; i++){
        printf("digite um numero: ");
        int num;
        scanf("%d", &num);
        push(&p, num);    
    }

    

    printf("pilha após remoção de um item:\n");
    pop(&p);
    exibirPilha(&p);  


    destruirPilha(&p);  

    return 0;
}
