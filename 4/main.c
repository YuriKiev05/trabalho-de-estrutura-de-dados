#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include "pilha.c"
#include "pilha.h"

void main() {
    char expressao[100];

    printf("Digite a expressão em NPI separada por espaços: \n");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = 0;

    int resultado = avaliarNPI(expressao);
    printf("Resultado: %d\n", resultado);


}
