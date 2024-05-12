#include <stdio.h>
#include <stdlib.h>


void adicionaX1(int x, int b)
{
    b = b + x;
}

void adicionaX2(int x, int* b)
{
    *b = *b + x;
}

void troca(int *x, int* y)
{
    int aux;

    aux = *x;
    *x = *y;
    *y = aux;
}

int main()
{
    int a = 10;
    int b = 20;

    adicionaX1(a, b);
    printf("O valor de b eh: %i\n", b); // 20

    adicionaX2(a, &b);
    printf("O valor de b eh: %i\n", b); // 30

    troca(&a, &b);
    printf("Novo valor de a: %i\n", a);
    printf("Novo valor de b: %i\n", b);  

    return 0;
}