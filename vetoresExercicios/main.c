// vetoresExercicios.c
// --------------------------------------------------
// Programa principal que utiliza funções do módulo funcoesVet
// para manipular vetores: inserção, ordenação, inversão e soma.
// --------------------------------------------------

#include <stdio.h>
#include "funcoesVet.h"

/**
 * Imprime os valores contidos em uma struct Vetor.
 * @param v Struct contendo os valores.
 * @param titulo Título descritivo para o grupo de valores.
 */
 
void imprimirVetor(Vetor v, const char *titulo) {
    printf("\n--- %s ---\n", titulo);
    for (int i = 0; i < MAX_VET; i++) {
        printf("Valor[%d] = %d\n", i, v.valores[i]);
    }
}

int main() {
    // Recebe os valores informados pelo usuário
    Vetor v = soInsereVetor(MAX_VET);
    imprimirVetor(v, "Valores originais");

    Vetor ordenado = ordenarVetor(v);
    imprimirVetor(ordenado, "Vetor ordenado");

    Vetor invertido = inverterVetor(v);
    imprimirVetor(invertido, "Vetor invertido");

    int soma = somarElementos(v);
    printf("\n--- Soma dos elementos: %d ---\n", soma);

    return 0;
}
