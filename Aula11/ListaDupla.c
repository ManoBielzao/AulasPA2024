#include "ListaDupla.h"

No *CriaNo(Livro book)
{
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->info = book;
    novoNo->prox = NULL;
    novoNo->ant = NULL;
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
        list->ultimo = no;
        list->marcador = no;
    }
    else
    {

        list->ultimo->prox = no;
        list->marcador = list->ultimo;
        list->ultimo = no;
        list->ultimo->ant = list->marcador;
       
    }    
    
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

void ImprimirListaInversa(Lista list)
{
    list.marcador = list.ultimo;
    while (list.marcador != NULL)
    {
        ImprimirLivro(list.marcador->info);
        list.marcador = list.marcador->ant;
        printf("*******************************\n");
    }
    
}

//PRIMEIRA VERSÃO DO EXCLUI

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
    lst->primeiro->ant = NULL;
    free(lst->marcador);
    lst->marcador = lst->primeiro;
    lst->contador--;
}

void ExcluiUltimo(Lista* lst)
{
    lst->marcador = lst->ultimo;
    lst->ultimo = lst->ultimo->ant;
    lst->ultimo->prox = NULL;
    free(lst->marcador);
    lst->marcador = lst->primeiro;
    lst->contador--;
}


void exclui(Lista* lst, char* nome)
{
    No *aux = NULL;
    No* anterior = lst->primeiro;
    lst->marcador = lst->primeiro;

    if (strcmp(nome, lst->marcador->info.titulo) == 0)
    {
        lst->primeiro = lst->primeiro->prox;
        lst->primeiro->ant = NULL;
        free(lst->marcador);
        lst->marcador = lst->primeiro;
        lst->contador--;
        return;
    }
 
    while (lst->marcador != NULL && strcmp(nome, lst->marcador->info.titulo) != 0)
    {
        lst->marcador = lst->marcador->prox;
    }

    if (lst->marcador == NULL)
    {
        printf("Tem esse elemento n padrinho, sinto mtt.\n");
        return;
    }
    

    if (lst->marcador->prox == NULL)
    {
        lst->ultimo = lst->marcador->ant;
    }
    

    anterior->prox = lst->marcador->prox;
    free(lst->marcador);

    lst->contador--;
    lst->marcador = lst->primeiro;
    
}