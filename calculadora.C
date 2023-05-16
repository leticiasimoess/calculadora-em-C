#include <stdio.h>

int main() {
    char operador;
    double num1, num2, resultado;
    int base;

    // Solicita ao usuário o tipo de operação desejada
    printf("Escolha o tipo de operacao:\n");
    printf("1. Decimal\n");
    printf("2. Binario\n");
    printf("3. Hexadecimal\n");
    printf("Digite a opcao: ");
    scanf("%d", &base);

    // Solicita ao usuário a operação desejada
    printf("Digite a operacao (+, -, *, /): ");
    scanf(" %c", &operador);

    // Solicita ao usuário os dois números
    printf("Digite o primeiro numero: ");
    if (base == 1) {
        scanf("%lf", &num1);
    } else if (base == 2) {
        scanf("%lf", &num1);
        num1 = (int)num1;  // Converte para inteiro
    } else if (base == 3) {
        scanf("%lf", &num1);
        num1 = (int)num1;  // Converte para inteiro
    }

    printf("Digite o segundo numero: ");
    if (base == 1) {
        scanf("%lf", &num2);
    } else if (base == 2) {
        scanf("%lf", &num2);
        num2 = (int)num2;  // Converte para inteiro
    } else if (base == 3) {
        scanf("%lf", &num2);
        num2 = (int)num2;  // Converte para inteiro
    }

    // Executa a operação desejada e armazena o resultado na variável 'resultado'
    switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Erro: Divisao por zero nao e permitida.\n");
                return 1;  // Retorna um código de erro
            }
            break;
        default:
            printf("Operacao invalida.\n");
            return 1;  // Retorna um código de erro
    }

    // Exibe o resultado da operação no formato apropriado
    if (base == 1) {
        printf("Resultado: %lf\n", resultado);
    } else if (base == 2) {
        printf("Resultado binario: %d\n", (int)resultado);
    } else if (base == 3) {
        printf("Resultado hexadecimal: %X\n", (int)resultado);
    }

    return 0;  // Retorna 0 para indicar que o programa foi executado com sucesso
}
