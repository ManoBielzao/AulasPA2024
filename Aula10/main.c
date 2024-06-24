#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro
{
    char titulo[40];
    char autor[40];
    int ano;
}Livro;

typedef struct no
{
    Livro info;
    struct no *prox;
}No;

typedef struct lista
{
    No *primeiro;
    No *marcador;
    No *ultimo;
    int contador;
}Lista;

No *CriaNo(Livro book)
{
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->info = book;
    novoNo->prox = NULL;
    return novoNo;
}

Lista criaLista()
{
    Lista novaLista = {NULL,NULL,NULL,0};

    return novaLista;
}

void addNo_na_Lista(No *no, Lista *list)
{
    if (list->contador == 0)
    {
        list->primeiro = no;
    }
    else
    {
        list->ultimo->prox = no;        
    }    
    list->ultimo = no;
    list->marcador = no;
    list->contador ++;
}

void ImprimirLivro(Livro book)
{
    printf("Autor: %s\n", book.autor);
    printf("Titulo: %s\n", book.titulo);
    printf("Ano: %d\n", book.ano);
}

void ImprimirLista(Lista list)
{
    list.marcador = list.primeiro;

    while (list.marcador != NULL)
    {
        ImprimirLivro(list.marcador->info);
        list.marcador = list.marcador->prox;
        printf("*******************************\n");
    }
    
}

// void exclui(Lista *lst, char *tit)
// {
//     while (lst->marcador != NULL)
//     {
//         No *aux = NULL;
//         No *excluido = NULL;
//         lst->marcador = lst->primeiro;

//         if (strcmp(lst->primeiro->info.titulo, tit) == 0)
//         {
//         lst->marcador = lst->primeiro;
//         lst->primeiro = lst->primeiro->prox;
//         free(lst->marcador);
//         lst->marcador = lst->primeiro;
//         }
//         else
//         {
//         aux = lst->marcador;

//         if (strcmp(lst->marcador->prox->info.titulo, tit) == 0)
//         {
//             excluido = lst->marcador->prox;
//             aux = excluido->prox;
//             free(excluido);
//             lst->marcador->prox = aux;
//         }
//         lst->marcador = lst->marcador->prox;
        
//         }
        
//     }

// }

void ExcluiPrimeiro(Lista* lst)
{
    lst->marcador = lst->primeiro;
    lst->primeiro = lst->primeiro->prox;
    free(lst->marcador);
    lst->marcador = lst->primeiro;
    lst->contador--; 
}


void exclui(Lista* lst, char* nome)
{
    No* anterior = lst->primeiro;
    lst->marcador = lst->primeiro;

    if (strcmp(nome, lst->marcador->info.titulo) == 0)
    {
        lst->primeiro = lst->primeiro->prox;
        free(lst->marcador);
        lst->marcador = lst->primeiro;
        lst->contador--;
        return;
    }
 
    while (lst->marcador != NULL && strcmp(nome, lst->marcador->info.titulo) != 0)
    {
        anterior = lst->marcador;
        lst->marcador = lst->marcador->prox;
    }

    if (lst->marcador == NULL)
    {
        printf("Tem esse elemento n padrinho, sinto mtt.\n");
        return;
    }
    

    if (lst->marcador->prox == NULL)
    {
        lst->ultimo = anterior;
    }
    

    anterior->prox = lst->marcador->prox;
    free(lst->marcador);

    lst->contador--;
    lst->marcador = lst->primeiro;
    
}
int main()
{
    Livro infantil = {"Rei leao", "Simba", 1998};
    Livro outro_infantil = {"Branca de neve", "Anoes", 1900};
    Livro de_hj = {"Narnia","Vcs",2024};

    Lista lista_de_livros = criaLista();

    No *novoNo = CriaNo(infantil);

    addNo_na_Lista(novoNo, &lista_de_livros);
    novoNo = CriaNo(outro_infantil);
    addNo_na_Lista(novoNo, &lista_de_livros);
    novoNo = CriaNo(de_hj);
    addNo_na_Lista(novoNo, &lista_de_livros);
    

    // ImprimirLivro(infantil);
    ImprimirLista(lista_de_livros);
    
    // char resposta[40];

    // printf("Qual livro quer excluir?\n");
    // scanf("%s", &resposta);

    // exclui(&lista_de_livros, resposta);

    ExcluiPrimeiro(&lista_de_livros);
    printf("\n");
    printf("Again\n");
    ImprimirLista(lista_de_livros);


    return 0;
}