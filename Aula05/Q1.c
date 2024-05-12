#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define milzao 1000

void ElementosVetor(int *N, int qnt)
{
    
    for (int i = 0; i < qnt; i++)
    {
        if (i == 0)
        {
            printf("Ok, agora digite os numeros que iremos somar.\n");
            scanf("%i", &N[i]);
            
        }
        else if ( i != 0){
        int falta = qnt - i;   
        printf("Continue digitando menoh, falta %i\n", falta);
        scanf("%i", &N[i]);
        falta--;
        
        }

    }
}

void ImprimirVetor(int *N, int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
        printf("Valor: %i\n", N[i]);
    }
    
}

void Somar(int *N, int qnt)
{
    int soma = 0;
    for (int i = 0; i < qnt; i++)
    {
        soma = soma + N[i];
    }
    printf("A soma em decimal eh: %i\n", soma);
    printf("A soma em hexadecimal eh: %x\n", soma);
    printf("A soma em octal eh: %o\n", soma);

}

int main()
{
    int N[milzao];
    int qnt = 0;

    printf("Digite a quantidade de numeros que quer somar:\n");
    scanf("%i", &qnt);

    ElementosVetor(N, qnt);
    ImprimirVetor(N, qnt);
    Somar(N, qnt);
    

    //%o = octal
    //%x = hexadecimal
    
}