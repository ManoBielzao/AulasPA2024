#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct 
{
    char experimento[40];
    float velocidade;
    float aceleracao;
    float distancia;
    float tempo;
}CVeic;

void InitCinematica(char *n, float d, float t, CVeic *v);

void calcVelocidade(CVeic * veiculo);

void calcAceleracao(CVeic * veiculo);


void MeuPrint(CVeic veiculo);