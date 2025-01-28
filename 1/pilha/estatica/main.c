#include <stdio.h>
#include <stdlib.h>
#include "pilhaEstatica.h"
#include "pilhaEstatica.c"





void main() {
    Pilha p;
    inicializarPilha(&p);

    push(&p, 10);
    push(&p, 20);
    pop(&p);
    exibirPilha(&p);  


}
