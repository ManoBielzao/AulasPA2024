#include <stdio.h>
#include <stdlib.h>

int Rev(int num) {
    int invertid = 0;
    while (num != 0) {
        invertid = invertid * 10 + num % 10;
        num /= 10;
    }
    return invertid;
}
int main() {
    int num1, num2;

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &num2);

    int soma_invertida = Rev(num1) + Rev(num2);

    printf("Os numeros %d, invertido para %d e %d invertido para %d quando somados sao: %d\n", num1, Rev(num1), num2, Rev(num2), soma_invertida);

    return 0;
}