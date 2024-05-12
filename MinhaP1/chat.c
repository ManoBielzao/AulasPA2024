#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define tamanho 4

typedef enum
{
    Soma,
    Media,
    Potencia,
    Raiz,
} Operacao;

void ImprimirVetor(double vet[], int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
        printf("O valor na posicao %d eh: %0.2lf\n", i, vet[i]);
    }
}

void executarOperacoes(double resultado[], int par, int par2, Operacao op)
{
    double result = 0.0;

    switch (op)
    {
        case Soma:
            result = par + par2;
            resultado[0] = result;
            break;

        case Media:
            result = (par + par2) / 2.0;
            resultado[1] = result;
            break;

        case Potencia:
            result = pow(par, par2);
            resultado[2] = result;
            break;

        case Raiz:
            result = pow(par, 1.0 / par2);
            resultado[3] = result;
            break;

        default:
            printf("Operacao invalida.\n");
            return;
    }
}

int main()
{
    double resultado[tamanho] = {0.0};  // Inicializa o vetor com zeros

    executarOperacoes(resultado, 2, 3, Soma);
    executarOperacoes(resultado, 2, 3, Media);
    executarOperacoes(resultado, 2, 3, Potencia);
    executarOperacoes(resultado, 2, 3, Raiz);

    ImprimirVetor(resultado, tamanho);

    return 0;
}