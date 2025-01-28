#include <stdio.h>
#include <conio.h>
#include "filaEstatica.c"
#include "filaEstatica.h"




int main() {
    Fila f;
    inicializarFila(&f);

    enfileirar(&f, 20);
    enfileirar(&f, 30);

    exibirFila(&f);  

    printf("Desenfileirado: %d\n", desenfileirar(&f)); 
    exibirFila(&f); 

    return 0;
}
