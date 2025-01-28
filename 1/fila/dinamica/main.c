#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.c"
#include "filaDinamica.h"


int main() {
    Fila f;
    inicializarFila(&f);
    int tam = 0;

    printf("fila criada. Quantos itens deseja adicionar?\n");
    scanf("%d", &tam);
    for(int i = 0; i<tam; i++){
        int num = 0;
        printf("digite o numero que quer enfileirar: ");
        scanf("%d", &num);
        enfileirar(&f, num);
    }


    exibirFila(&f);  

    printf("Desenfileirado: %d\n", desenfileirar(&f));  
    exibirFila(&f); 

    return 0;
}
