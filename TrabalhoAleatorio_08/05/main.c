#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    // char nome[40];
    // char subst[40];
    // char palavra_nova[40];
    // char *sub;
    // printf("Escreva uma merda de frase:\n");
    // gets(nome);

    // char vet[30];
        
    // printf("Escreva a palavra que deseja substituir:\n");
    // gets(subst);

    // printf("Escreva a nova palavra:\n");
    // gets(palavra_nova);

    // size_t tamanho = strlen(subst);

    // if (strncmp(nome,subst, tamanho) == 0)
    // {
    //     sub = strtok(nome, " ");
    // }

    // printf("Sub = %c", sub);
    
    
    // printf("%s", nome);
    // char palavre[40] = "\0";
    // char *pont = "se liga na minha arma de piranhas";
    // char *otherpont; 
    // strcat(palavre, pont);
    // printf("%s\n", palavre);
    // // printf("%s\n", palavre);
    // // possue um limite de caracteres, apenas 3
    // // char otherpont[30];

    // strcpy(palavre, "a");
    // printf("%s\n", palavre);

    // char word[] = "vamos nos mamar mais";
    // char *pch;

    // strcat(subst, pch);
    // while(pch != nome)
    // {
    //     pch = strtok(subst, " ");
    // }
    // printf("Ponteiro: %s\n", pch);
char frase[1000];
    char palavra_original[100];
    char nova_palavra[100];

    // Solicita ao usuário que insira uma frase
    printf("Digite uma frase: ");
    scanf("%999[^\n]%*c", frase);

    // Solicita ao usuário que insira a palavra a ser substituída
    printf("Digite a palavra que deseja substituir: ");
    scanf("%s", palavra_original);

    // Solicita ao usuário que insira a nova palavra
    printf("Digite a nova palavra: ");
    scanf("%s", nova_palavra);

    // Tamanho das palavras
    int tamanho_palavra_original = strlen(palavra_original);
    int tamanho_nova_palavra = strlen(nova_palavra);

    // Itera sobre a frase
    for (int i = 0; i <= strlen(frase) - tamanho_palavra_original; i++) {
        // Se encontrar a palavra original
        if (strncmp(&frase[i], palavra_original, tamanho_palavra_original) == 0) {
            // Substitui a palavra original pela nova palavra
            strncpy(&frase[i], nova_palavra, tamanho_nova_palavra);
            // Se a nova palavra for menor que a original, preenche o espaço com espaços em branco
            if (tamanho_nova_palavra < tamanho_palavra_original) {
                memset(&frase[i + tamanho_nova_palavra], ' ', tamanho_palavra_original - tamanho_nova_palavra);
            }
            // Move o ponteiro para o próximo caractere depois da nova palavra
            i += tamanho_nova_palavra - 1;
        }
    }

    // Exibe a frase modificada
    printf("Frase modificada: %s\n", frase);
    
    return 0;
}