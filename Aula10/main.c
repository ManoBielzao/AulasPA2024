#include <stdio.h>
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
}No;

typedef struct lista
{
    No*primeiro;
    No*marcador;
    int contador;
}Lista;

No CriaNo(Livro book)
{
    No novoNo;
    novoNo.info = book;
    novoNo.prox = NULL;
    return novoNo;
}

Lista criaLista()
{
    Lista novaLista = {NULL,NULL,0};

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
        list->marcador->prox = no;
        
    }    
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
int main()
{
    Livro infantil = {"Rei leao", "Simba", 1998};
    Livro outro_infantil = {"Branca de neve", "Anoes", 1900};
    Lista lista_de_livros = criaLista();

    No novoNo = CriaNo(infantil);
    No no_renovado = CriaNo(outro_infantil);

    addNo_na_Lista(&novoNo, &lista_de_livros);
    addNo_na_Lista(&no_renovado, &lista_de_livros);

    // ImprimirLivro(infantil);
    ImprimirLista(lista_de_livros);

    return 0;
}