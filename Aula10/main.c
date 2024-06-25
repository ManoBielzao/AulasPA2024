#include "Lista.h"

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

    ExcluiUltimo(&lista_de_livros);
    printf("\n");
    printf("Again\n");
    ImprimirLista(lista_de_livros);


    return 0;
}