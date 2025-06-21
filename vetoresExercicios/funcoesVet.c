// funcoesVet.c
// -------------------------------------------------------------------
// Implementação das funções de manipulação de vetor encapsulado
// na struct Vetor. Este módulo permite inserir, exibir, ordenar,
// inverter e somar os valores de um vetor de inteiros.
// -------------------------------------------------------------------

#include <stdio.h>
#include "funcoesVet.h"

/**
 * Solicita ao usuário que insira valores inteiros para preencher uma struct Vetor.
 *
 * @param tam_vetor Quantidade de elementos a serem inseridos (deve ser <= MAX_VET).
 * @return Vetor preenchido com os valores inseridos pelo usuário.
 */
Vetor soInsereVetor(int tam_vetor) {
    Vetor v;

    printf("\n---------- Insercao de %d valores inteiros ----------\n", tam_vetor);
    for (int i = 0; i < tam_vetor; i++) {
        printf("Informe o valor da posicao %d: ", i + 1);
        scanf("%d", &v.valores[i]);  // Armazena cada valor no array da struct
    }

    return v;  // Retorna a struct preenchida
}

/**
 * Insere valores inteiros diretamente em um array local e os imprime.
 * Não utiliza struct nem retorna os dados.
 *
 * @param tam_vetor Quantidade de elementos a serem inseridos.
 */
void inserirVetor(int tam_vetor) {
    int valores[tam_vetor];

    printf("\n---------- Insercao de %d valores inteiros ----------\n", tam_vetor);
    for (int i = 0; i < tam_vetor; i++) {
        printf("Informe o valor da posicao %d: ", i + 1);
        scanf("%d", &valores[i]);  // Preenche array local
    }

    // Imprime os valores armazenados
    printf("\n--- Valores inseridos ---\n");
    for (int i = 0; i < tam_vetor; i++) {
        printf("Valor[%d] = %d\n", i, valores[i]);
    }
}

/**
 * Ordena os valores do vetor em ordem crescente (Bubble Sort).
 *
 * @param v Struct Vetor contendo os dados originais.
 * @return Novo Vetor com os valores ordenados.
 */
Vetor ordenarVetor(Vetor v) {
    Vetor ordenado = v;  // Cria cópia local da struct recebida

    // Algoritmo de ordenação simples: Bubble Sort
    for (int i = 0; i < MAX_VET - 1; i++) {
        for (int j = i + 1; j < MAX_VET; j++) {
            if (ordenado.valores[i] > ordenado.valores[j]) {
                // Troca os valores se estiverem fora de ordem
                int temp = ordenado.valores[i];
                ordenado.valores[i] = ordenado.valores[j];
                ordenado.valores[j] = temp;
            }
        }
    }

    return ordenado;  // Retorna vetor ordenado
}

/**
 * Inverte a ordem dos elementos do vetor.
 *
 * @param v Struct Vetor original.
 * @return Novo Vetor com os valores invertidos.
 */
Vetor inverterVetor(Vetor v) {
    Vetor invertido;

    // Copia os elementos em ordem inversa
    for (int i = 0; i < MAX_VET; i++) {
        invertido.valores[i] = v.valores[MAX_VET - 1 - i];
    }

    return invertido;
}

/**
 * Calcula a soma de todos os elementos do vetor.
 *
 * @param v Struct Vetor com os dados.
 * @return Resultado da soma de todos os valores.
 */
int somarElementos(Vetor v) {
    int soma = 0;

    for (int i = 0; i < MAX_VET; i++) {
        soma += v.valores[i];  // Soma acumulada
    }

    return soma;  // Retorna o total
}
