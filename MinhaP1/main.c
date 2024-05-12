#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#define tamanho 4

typedef enum
{
   Soma,
   Media,
   Potencia,
   Raiz,

}Operacao;

void ImprimirVetor(double *vet, int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
        printf("O valor na posicao %d eh: %0.2lf\n", i, vet[i]);
    }
    
}

void executarOperacoes(double *resultado, int par, int par2, Operacao op)
{
    static double result;
    int qnt = tamanho;
    int parametro2 = par2;
    int i;


    
        switch (op)
    {
    case Soma:
    
    for (i = 0; i < qnt; i++)
    {
        if (resultado[i] != 0)
        {
    result = par + par2;
    resultado[i] = result;
    ImprimirVetor(resultado, tamanho);
        }
break;
    
    }
    break;

    case Media:
    for (i = 0; i < qnt; i++)
    { if (resultado[i] != 0)
    {
     result = ((double)par + (double)par2) / 2;
    resultado[i] = result;
    ImprimirVetor(resultado, tamanho);
    break;
    }
    }
    break;
    

    case Potencia:
    for (i = 0; i < qnt; i++)
    {
        if (resultado[i] != 0)
        {
           result = pow(par, par2);
    resultado[i] = result;
    ImprimirVetor(resultado, tamanho);
     break;
        }
        
    }
    break;
    

    case Raiz:
    resultado[i] = result;
    for (i = 0; i < qnt; i++)
    {
        if (resultado[i] != 0)
        {
            result = pow(par, (1/par2));
            resultado[i] = result;
    ImprimirVetor(resultado, tamanho);
    break;
        }
        
    }
     

    default:
        break;
    }
    }
    
    




int main()
{
    int vet[tamanho];
    double resultado[tamanho];

    executarOperacoes(resultado, 2, 3, Soma);
    executarOperacoes(resultado, 2, 3, Media);
    executarOperacoes(resultado, 2, 3, Potencia);
    executarOperacoes(resultado, 2, 3, Raiz);

    
    return 0;
}
