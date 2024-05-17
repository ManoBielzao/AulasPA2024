#include <stdlib.h>
#include "biblioteca.h"


int main()
{
    CVeic exp_1;
    InitCinematica("Teste 1", 1000, 10, &exp_1);
    calcVelocidade(&exp_1);
    calcAceleracao(&exp_1);


    MeuPrint(exp_1);


    return 0;
}