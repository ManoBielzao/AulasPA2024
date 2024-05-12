#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum tipo
{
    MULT,
    TEXT
}TipoTela;


typedef struct tela
{
    char titulo[40];
    char info[60];
    int opcao;
    TipoTela tipo_tela;
}Tela;

Tela telas_prog[3] = 
{
    {"MENU", "1 para prox e 2 para sair", 0, MULT},
    {"Tela 2", "1 p voltar, 2 p prox e 3 p sair", 0, MULT},
    {"Tela 3", "1 p voltar, 2 p MENU e 3 p sair", 0, MULT},


};

void ImprimirTela(int n_tela)
{
    system("cls");
    printf("%s\n", telas_prog[n_tela].titulo);
    printf("%s\n", telas_prog[n_tela].info);

}
int Navega(int escolha, int estado)
{
    if (escolha == 1 && estado == 0)
    {
        return estado = 1;
    }
    else if (escolha == 2 && estado == 1)
    {
        return estado = 2;
    }
    else if (escolha == 1 && estado == 1)
    {
        return estado = 0;
    }
    else if (escolha == 2 && estado == 2)
    {
        return estado = 0;
    }
    else 
    {
        return 100;
    }

} 

int main()
{
    int escolha = 0;
    int estado = 0;

    
    switch (estado)
    {
    case 0:
        ImprimirTela(0);
        scanf("%i", &escolha);
        Navega(escolha, estado);
        break;
    case 1:
    ImprimirTela(1);
        scanf("%i", &escolha);
        Navega(escolha, estado);
        break;

    case 2:
    ImprimirTela(2);
    scanf("%i", &escolha);
    Navega(escolha, estado);

    default:
        break;
    }


   
   

    return 0;
}


    // char palavre[40];
    // char *pont = " se liga na minha arma de piranhas";
    // //char *otherpont; possue um limite de caracteres, apenas 3
    // char otherpont[30];

    // strcpy(palavre, "a");
    // printf("%s\n", palavre);
    // strcat(palavre, " eeeeeeeeeeeee");
    // printf("%s\n", palavre);
    // strcat(palavre, pont);
    // printf("%s\n", palavre);

    // printf("escreve ai uma string menoh:\n");
    // scanf("%s", otherpont);
    // printf("teu string ae: %s\n", otherpont);
    // strcat(palavre, otherpont);
    // printf("oia ai o bgl concatenado %s\n", palavre);


// char palavra[40];

// do
// {
//     printf("digite uma palavre kkkkkkk:\n");
//     scanf("%s", palavra);
    
// } while (strcmp("palavre", palavra) != 0);

// printf("Ae krai kkkkkkkkk, demorou\n");

// char word[] = "vamos nos mamar mais";
//     char *pch;
    
//     pch = strtok(word, " ");
//     printf("Ponteiro: %s\n", pch);    