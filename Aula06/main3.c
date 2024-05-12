#include <stdio.h>
#include <stdlib.h>


void ImprimirVetor(int *vet, int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {
        printf("O valor na P%i", vet[i]);
    }
    
}


int main()
{
    int p;
    int *d;
    int q = 10;
    float *j;
    float t = 15.0;
    j = &t;
    p = &q;
    d = j;


    printf("O valor de p eh %i\n", p);
    printf("O valor de q eh %i\n", q);
    printf("O valor de onde d aponta eh %i\n", *d);
    printf("O end de p eh %p\n", &p);


    return 0;
}