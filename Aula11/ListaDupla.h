#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    struct no *ant;    
}No;

typedef struct lista
{
    No*primeiro;
    No*marcador;
    No*ultimo;
    int contador;
}Lista;

No *CriaNo(Livro book);
Lista criaLista();
void addNo_na_Lista(No *no, Lista *list);
void ImprimirLivro(Livro book);
void ImprimirLista(Lista list);
void ImprimirListaInversa(Lista list);
void ExcluiPrimeiro(Lista* lst);
void ExcluiUltimo(Lista* lst);
void exclui(Lista* lst, char* nome);
