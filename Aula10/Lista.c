#include "Lista.h"

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
void ExcluiUltimo(Lista *lst)
{
    No *anterior = lst->primeiro;
    lst->marcador = lst->primeiro;

    if (lst->marcador == lst->ultimo)
    {
        free(lst->marcador);
        printf("Meu nobre, sua lista ta vazia agr.\n");
    }
    while (lst->marcador != NULL && lst->marcador->prox != NULL)
    {
        anterior = lst->marcador;
        lst->marcador = lst->marcador->prox;
    }
    lst->ultimo = anterior;
    lst->ultimo->prox = NULL;
    free(lst->marcador);
    lst->marcador = lst->primeiro;
    lst->contador--;
}