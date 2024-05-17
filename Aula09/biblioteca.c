#include "biblioteca.h"

void calcAceleracao(CVeic *veiculo)
{
    veiculo->aceleracao = veiculo->velocidade / veiculo->tempo;
}

void calcVelocidade(CVeic * veiculo)
{
    veiculo->velocidade = veiculo->distancia / veiculo->tempo;
}


void InitCinematica(char *n, float d, float t, CVeic *v)
{
    v->distancia = d;
    v->tempo = t;
    strcpy(v->experimento, n);

}

//n esta sendo utilizado no codigo.
void PreparaPrint(char * msg)
{
    char msg_resultado[80] = "";
    strcpy(msg_resultado,"*---*");
    strcat(msg_resultado, msg);

    printf("%s", msg_resultado);
}

void MeuPrint(CVeic veic)
{
    printf("*********************\n");
    printf("%s\n", veic.experimento);
    printf("Distancia: %.2f\n", veic.distancia);
    printf("Tempo: %.2f\n", veic.tempo);
    printf("Velocidade: %.2f\n", veic.velocidade);
    printf("*********************\n");
}