#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Lista {
    int valor;
    struct Lista *proximo;
} Lista;

int main() {
    Lista lista[MAX];

    // Construção da "lista encadeada" com vetor
    for (int i = 0; i < MAX; i++) {
        lista[i].valor = i * 3;

        // Se não for o último elemento, aponta para o próximo no vetor
        if (i < MAX - 1) {
            lista[i].proximo = &lista[i + 1];
        } else {
            lista[i].proximo = NULL;  // último elemento aponta para NULL
        }
    }

    // Impressão dos elementos e seus ponteiros
    for (int i = 0; i < MAX; i++) {
        printf("Valor: %2d\tEndereco atual: %p\tProximo: %p",
               lista[i].valor,
               &lista[i],
               lista[i].proximo);

        if (lista[i].proximo != NULL) {
            printf("\t-> Valor apontado: %d\n", lista[i].proximo->valor);
        } else {
            printf("\t-> Valor apontado: NULL\n");
        }
    }

    return 0;
}
