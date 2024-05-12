#include <stdio.h>
#include <stdlib.h>

#define max_prod 10

typedef float Precos;

typedef enum prod{
    TV,
    SOM,
    CELULAR
}Produto;

Precos lista_precos[max_prod];
Produto lista_de_produtos[max_prod];

void ImprimirProdutos(int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
       switch (lista_de_produtos[i])
   {
   case TV:
    printf("O produto %d eh uma TV e custa R$%.2f.\n", i, lista_precos[i]);
    break;
    case SOM:
    printf("O produto %d eh um Som e custa R$%.2f.\n", i, lista_precos[i]);
    break;
    case CELULAR:
    printf("O produto %d eh um Celular e custa R$%.2f.\n", i, lista_precos[i]);
    break;

   default:
   printf("Opção invalida.\n");
    break;
   }
    }


}

int AddProduto(Produto prod, Precos preco)
{
    static int idx = 0;
    lista_de_produtos[idx] = prod;
    lista_precos[idx] = preco;
    idx++;

    return idx;
}

int SolicitaDados(){
        Produto prod_escol;
        float preco;
        int idx;

      printf("Digite o produto desejado:\n");
      printf("Digite 0 para TV\n");
      printf("Digite 1 ppara Som\n");
      printf("Digite 2 para Celular\n");
      scanf("%d", &prod_escol);

if (prod_escol != -1){

    printf("Digite o preco do produto: ");

      scanf("%f", &preco);
      idx = AddProduto(prod_escol, preco);
      return idx;
}

      return prod_escol;
    }

int main()
{

    // Produto produto_escolhido = CELULAR;

    // ImprimirProduto(produto_escolhido);
// int indice;
// indice = AddProduto(TV, 9999.90);
// indice = AddProduto(SOM, 1000);
// indice = AddProduto(CELULAR, 20000.99);
// ImprimirProdutos(indice);
int qnt = 0;
int cont = 0;

while (qnt >= 0 && qnt < max_prod)
    {
        (SolicitaDados()!=-1) ? (cont++) :(qnt = -1);
    }

    ImprimirProdutos(cont);
    return 0;
}




//exemplo merda sobre typedef
// typedef float batata;

// int main()
// {
//     batata valor = 3.3;
//     printf("O valor eh: %f\n", valor);
//     float valor2 = 2.3;
//     printf("O valor 2 eh: %f\n", valor2);

//     return 0;
// }