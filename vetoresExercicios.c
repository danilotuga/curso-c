// vetoresExercicios.c
#include <stdio.h>
#include "funcoesVet.h"

int main() {
    // Versão com struct retornando vetor
    Vetor v = soInsereVetor(MAX_VET);

    printf("\n--- Valores armazenados na struct Vetor ---\n");
    for (int i = 0; i < MAX_VET; i++) {
        printf("Valor[%d] = %d\n", i, v.valores[i]);
    }

    // Versão direta (sem struct)
    printf("\n--- Inserção direta com função auxiliar ---\n");
    inserirVetor(MAX_VET);

    return 0;
}
