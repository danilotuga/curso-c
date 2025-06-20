#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Função que copia o conteúdo de uma string para outra.
/// Parâmetros:
///   - CopiaDaqui: ponteiro para a string de origem.
///   - ColaDali: ponteiro para onde a string será copiada.
void CopiarString(char *CopiaDaqui, char *ColaDali) {

    // Enquanto não chegar ao final da string de origem
    while (*CopiaDaqui != '\0') {
        printf("\n Copiando -> %c\n", *CopiaDaqui); // Mostra o caractere atual sendo copiado

        *ColaDali = *CopiaDaqui;  // Copia o caractere da origem para o destino
        ++CopiaDaqui;             // Avança para o próximo caractere da origem
        ++ColaDali;               // Avança para o próximo espaço no destino
    }

    *ColaDali = '\0'; // Finaliza a string destino com o caractere nulo
}

int main() {
    // Exemplo 1: Cópia de strings com ponteiros
    char string1[] = "Bolo de Fuba";  // String de origem
    char string2[20];                 // Buffer de destino (tamanho maior que a string1)

    CopiarString(string1, string2);   // Copia string1 para string2

    // Impressão das strings para verificar resultado
    printf("\nString 1 --> %s\n", string1);
    printf("String 2 --> %s\n", string2);

    // Exemplo 2: Contagem de ocorrências de uma palavra em um texto
    char fraseTeste[300] = "O teste deu certo afinal o teste e muito fixe. o teste tem por objectivo saber quantas vezes aparece teste e imprimir a palavra teste";

    char *ptr = fraseTeste; // Ponteiro para percorrer a string
    int contador = 0;       // Contador de ocorrências da palavra

    // Loop que usa strstr para localizar a palavra "teste"
    while ((ptr = strstr(ptr, "teste")) != NULL) {
        contador++;  // Incrementa o contador de ocorrências

        // Mostra a posição atual do ponteiro e o número de caracteres que será pulado
        printf("\nptr atual --> %p | avanço: %lu\n", (void *)ptr, strlen("teste"));

        // Avança o ponteiro além da palavra atual para não contar ela novamente
        ptr += strlen("teste");
    }

    printf("\nA palavra 'teste' apareceu %d vezes.\n", contador);

    return 0;
}
