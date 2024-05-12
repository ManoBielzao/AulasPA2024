#include <stdio.h>
#include <stdlib.h>



int main()
{
    int matricula = 777;
    int * p_mat;
    int * p_outro;

    p_mat = &matricula;
    p_outro = &matricula; //ou p_outro = p_matricula
    
    //Trocando o valor de matricula
    *p_mat = 888;

    printf("Valor da matricula %i\n", matricula);
    printf("VAlor de p_mat: %i\n", *p_mat);
    printf("Valor de p_outro: %i\n", *p_outro);
    printf("Endereco onde p_mat aponta: %p\n", p_mat);


    return (0);
}