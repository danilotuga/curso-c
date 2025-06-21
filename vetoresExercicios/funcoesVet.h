// funcoesVet.h
// --------------------------------------------------
// Módulo de operações com vetor encapsulado em struct
// --------------------------------------------------

#ifndef FUNCOESVET_H
#define FUNCOESVET_H

#define MAX_VET 3  // Tamanho fixo do vetor usado em todas as operações

/**
 * Struct que representa um vetor de inteiros com tamanho fixo.
 */
typedef struct {
    int valores[MAX_VET];
} Vetor;

/**
 * Solicita ao usuário a inserção de valores e retorna a struct preenchida.
 * @param tam_vetor Quantidade de valores a serem inseridos.
 * @return Vetor preenchido.
 */
Vetor soInsereVetor(int tam_vetor);

/**
 * Versão alternativa que apenas insere e imprime valores (sem retorno).
 * @param tam_vetor Quantidade de valores.
 */
void inserirVetor(int tam_vetor);

/**
 * Ordena os valores do vetor em ordem crescente.
 * @param v Vetor a ser ordenado.
 * @return Vetor ordenado.
 */
Vetor ordenarVetor(Vetor v);

/**
 * Retorna os valores do vetor em ordem inversa.
 * @param v Vetor a ser invertido.
 * @return Vetor invertido.
 */
Vetor inverterVetor(Vetor v);

/**
 * Soma todos os elementos do vetor.
 * @param v Vetor cujos elementos serão somados.
 * @return Soma dos elementos.
 */
int somarElementos(Vetor v);

#endif
