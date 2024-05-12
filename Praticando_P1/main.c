//melhorei bastante :D

#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

typedef enum{
Soma = 0,
Media,
Minimo,
Maximo,
Todas,
Nenhuma,

}Operacoes;

void ImprimirVetor(int *vet, int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
        if (&vet[i] == NULL)
            {
                break;
            }
        else if (i == 0)
        {
            printf("{%d, ", vet[i]);
        }
        else if (i + 1 == qnt)
        {
            printf("%d}", vet[i]);
        }
        else if (0 < i && i < qnt)
        {
            printf("%d, ", vet[i]);
        }
        
    }
    
}

void OperacoesComVetores(int *vet, int qnt, Operacoes op)
{
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int soma1 = 0;
    int soma2 = 0;
    float media;
    int min;
    int max = 0;
    int resposta;
    switch (op)
    {

    case Soma:
    
        for (int i = 0; i < qnt; i++)
        {
            soma1 = soma1 + vet[i]; 
        }
    printf("A soma deu: %d\n", soma1);
        
    break;

    case Media:
    
    for (int i = 0; i < qnt; i++)
    {
        if (vet[i] != 0){
        soma2 = soma2 + vet[i];
        count1++;
        }
    }
    if (count1 != 0) { 
        media = (float)soma2 / count1;
        printf("A media deu: %.2f\n", media);
    } else {
        printf("Nao foi possivel calcular a media, vetor vazio.\n");
    }

    break;

    case Minimo:

    for (int i = 0; i < qnt; i++)
    {
        if (min > vet[i])
        {
            count2 = i + 1;
            min = vet[i];        
        }
        
    }
    printf("O valor minimo do vetor eh: %d na posicao %d\n", min, count2);
    
    break;

    case Maximo:
    for (int i = 0; i < qnt; i++)
    {
        if (max < vet[i])
        {
            max = vet[i];
            count3 = i + 1;        
        }
        
    }
    printf("O valor maximo do vetor eh: %d na posicao %d\n", max, count3);
    
    break;

    case Todas:
            OperacoesComVetores(vet, qnt, Soma);
            OperacoesComVetores(vet, qnt, Media);
            OperacoesComVetores(vet, qnt, Minimo);
            OperacoesComVetores(vet, qnt, Maximo);
break;

    case Nenhuma:
    
    printf("Que pena, gostaria de visualizar seu vetor?\n");
    printf("0 --- Sim.\n");
    printf("1 --- Nao.\n");
    scanf("%d", &resposta);
    printf("\n");
    if (resposta == 0)
    {
        printf("Perfeito, fique com seu belo vetor:\n");
        ImprimirVetor(vet, qnt);
    }
    else{
    printf("Nenhuma operacao desejada, cancelando programa.");
    }
    break;
    
    default:
    break;
    
    }
    

}

int Interface()
{
    int resposta;
   printf("Dentre as operacoes disponiveis, escolha a que desejar realizar em seu vetor:\n");
    printf("0 --- Soma.\n");
    printf("1 --- Media.\n");
    printf("2 --- Minimo.\n");
    printf("3 --- Maximo.\n");
    printf("4 --- Todas.\n");
    printf("5 --- Nenhuma operacao.\n");
    scanf("%d", &resposta);
    printf("\n");
    return resposta;
}

void AddVetor(int *vet, int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
        printf("Por favor adicione um valor inteiro para a posicao %d\n", i);
        scanf("%d", &vet[i]);
    }
    
}



int main(int argc, char *argv[])
{
    int vet[tamanho];
    int qnt = tamanho;
    
    AddVetor(vet, qnt);
    
    int operacao = Interface();

    OperacoesComVetores(vet, qnt, operacao);

    return 0;
}