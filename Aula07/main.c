#include<stdio.h>
#include<stdlib.h>

#define MAX_PROD 50

typedef float Precos;

typedef enum {
    TV = 1,
    SOM,
    CELULAR
} Produto;

typedef struct {
    Produto prod;
    Precos preco;
} Itens;

void imprimirProdutos(Itens *itens, int qnt)
{
    for(int i = 0; i < qnt; i++)
    {
        switch(itens[i].prod)
        {
            case TV:
                printf("O produto %d eh uma TV e custa R$%.2f.\n", 
                        i, itens[i].preco);
                break;
            case SOM:
                printf("O produto %d eh um SOM e custa R$%.2f.\n", 
                        i, itens[i].preco);
                break;
            case CELULAR:
                printf("O produto %d eh um CELULAR e custa R$%.2f.\n",
                        i, itens[i].preco);
                break;
            default:
                printf("algo errado.\n");
        }
    }
}

int addProduto(Itens *itens, Produto prod, Precos preco, int idx)
{    
    itens[idx].prod = prod;
    itens[idx].preco = preco;
    idx++;

    return idx;
}

Produto tela()
{
    Produto escolha;
    
    printf("Escolha um produto:\n");
    printf("1 para TV\n2 para SOM\n3 para CELULAR\n0 para sair\n");
    scanf("%u", &escolha);
    
    return escolha;
}

int main()
{
    int indice = 0;
    Itens itens[MAX_PROD];
    Produto prod;
    Precos preco;

    do
    {
        prod = tela();
        if(prod != 0)
        {
            printf("Insira o preco do produto: ");
            scanf("%f", &preco);
            indice = addProduto(itens, prod, preco, indice);
        }
    } while(prod != 0);

    imprimirProdutos(itens, indice);
    
    return 0;
}