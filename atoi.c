#include <stdio.h>

// Implementação da função ft_atoi (versão simplificada de atoi)
int ft_atoi(const char *str) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // Ignora espaços e caracteres de controle (tab, newline, etc)
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) {
        i++;
    }

    // Verifica sinal
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Converte os dígitos em número
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

int main(void) {
    int valor = ft_atoi("777 22");  // Vai parar ao encontrar o 'a'
    printf("Resultado e --> %d\n", valor);
    return 0;
}
