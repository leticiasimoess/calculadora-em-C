#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Função para converter um número binário em decimal
int bin_to_dec(char *bin) {
    int dec = 0;
    int len = strlen(bin);
    for (int i = 0; i < len; i++) {
        if (bin[i] == '1') {
            dec += pow(2, len - i - 1);
        }
    }
    return dec;
}

// Função para converter um número hexadecimal em decimal
int hex_to_dec(char *hex) {
    int dec = 0;
    int len = strlen(hex);
    for (int i = 0; i < len; i++) {
        int digit = 0;
        if (isdigit(hex[i])) {
            digit = hex[i] - '0';
        } else {
            digit = toupper(hex[i]) - 'A' + 10;
        }
        dec += digit * pow(16, len - i - 1);
    }
    return dec;
}

// Função para converter um número decimal em binário
void dec_to_bin(int dec, char *bin) {
    int index = 0;
    while (dec > 0) {
        bin[index++] = (dec % 2) + '0';
        dec /= 2;
    }
    bin[index] = '\0';
    strrev(bin);
}

// Função para converter um número decimal em hexadecimal
void dec_to_hex(int dec, char *hex) {
    int index = 0;
    while (dec > 0) {
        int digit = dec % 16;
        if (digit < 10) {
            hex[index++] = digit + '0';
        } else {
            hex[index++] = digit - 10 + 'A';
        }
        dec /= 16;
    }
    hex[index] = '\0';
    strrev(hex);
}

int main() {
    char operador;
    char num1_str[33], num2_str[33], resultado_str[33];
    int num1_dec, num2_dec, resultado_dec;
    char num1_bin[33], num2_bin[33], resultado_bin[33];
    char num1_hex[9], num2_hex[9], resultado_hex[9];
    int base;

    // Solicita ao usuário a base de operação desejada
    printf("Digite a base de operacao desejada (2 para binario, 10 para decimal, 16 para hexadecimal): ");
    scanf("%d", &base);

    // Solicita ao usuário a operação desejada
    printf("Digite a operacao (+, -, *, /): ");
    scanf(" %c", &operador);

    // Solicita ao usuário o primeiro número
    printf("Digite o primeiro numero: ");
    scanf("%s", num1_str);

    // Converte o primeiro número para decimal
    if (base == 2) {
        num1_dec = bin_to_dec(num1_str);
    } else if (base == 16) {
        num1_dec = hex_to_dec(num1_str);
    } else {
        num1_dec = atoi(num1_str);
    }

    // Solicita ao usuário o segundo número
    printf("Digite o segundo numero: ");

    // Converte o segundo número para decimal
if (base == 2) {
    num2_dec = bin_to_dec(num2_str);
} else if (base == 16) {
    num2_dec = hex_to_dec(num2_str);
} else {
    num2_dec = atoi(num2_str);
}

// Executa a operação desejada em decimal
switch (operador) {
    case '+':
        resultado_dec = num1_dec + num2_dec;
        break;
    case '-':
        resultado_dec = num1_dec - num2_dec;
        break;
    case '*':
        resultado_dec = num1_dec * num2_dec;
        break;
    case '/':
        if (num2_dec != 0) {
            resultado_dec = num1_dec / num2_dec;
        } else {
            printf("Erro: Divisao por zero nao e permitida.\n");
            return 1;  // Retorna um código de erro
        }
        break;
    default:
        printf("Operacao invalida.\n");
        return 1;  // Retorna um código de erro
}

// Converte o resultado de decimal para binário e hexadecimal
dec_to_bin(resultado_dec, resultado_bin);
dec_to_hex(resultado_dec, resultado_hex);

// Exibe o resultado nas diferentes bases
printf("Resultado em decimal: %d\n", resultado_dec);
printf("Resultado em binario: %s\n", resultado_bin);
printf("Resultado em hexadecimal: %s\n", resultado_hex);

return 0;  // Retorna 0 para indicar que o programa foi executado com sucesso
}

