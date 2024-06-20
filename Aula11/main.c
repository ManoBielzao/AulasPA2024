#include "ListaDupla.h"

//Lista Duplamente Encadeada
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
    // printf("Agora ela inversa:\n");
    // ImprimirListaInversa(lista_de_livros);

    // printf("Excluindo o primeiro:\n");
    // ExcluiPrimeiro(&lista_de_livros);
    // ImprimirLista(lista_de_livros);

    //printf("Excluindo algo que eu queira:\n");
    // exclui(&lista_de_livros, "Branca de neve");
    //ImprimirLista(lista_de_livros);

    ExcluiUltimo(&lista_de_livros);
    printf("Excluindo o ultimo:\n");
    ImprimirLista(lista_de_livros);
    


    return 0;
}