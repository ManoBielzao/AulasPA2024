#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PRECOS 5
// #define NUM_CODIGO 3

float precos[NUM_PRECOS] = {1.0, 1.1, 1.2, 1.3, 1.4};
float precos_rotacionados[NUM_PRECOS];
// int codigos[NUM_CODIGO];

int solicitaPreco()
{
    int idx = 0;
   do 
   {
    printf("Digite um valor: ");
    scanf("%f", &precos[idx]);
    idx++;
   }while(idx < NUM_PRECOS && precos[idx - 1] != -1);
         
    if (precos[idx-1] == -1)
    {
        idx--;
    }
    

   return idx;
}


void printVetorGlobal(int qnt_ele)
{
    int idx = 0;

   while(idx < qnt_ele)
   {
      printf("O preco do elemento %i eh: %0.2f\n", idx, precos[idx]);
      idx++;
   }
}

void rotacionaVetor()
{
    int j = NUM_PRECOS - 1;

   for(int i = 0; i < NUM_PRECOS; i++, j--)
   {
     precos_rotacionados[i] = precos[j];
   }

   for (int i = 0; i < NUM_PRECOS; i++)
   {
    precos[i] = precos_rotacionados[i];
   }
   
}


int main()
{
  // printf("vetor original:\n");
  // printVetorGlobal(NUM_PRECOS);

  // int qnt = solicitaPreco();
  
  // printf("Vetor digitado:\n");
  // printVetorGlobal(qnt);
  
  // rotacionaVetor();


  // printf("Vetor rotacionado:\n");
  // printVetorGlobal(NUM_PRECOS);

// printf("O valor como int %i\n", 75);
// printf("O valor como char %c\n", 75);


printf("Uma palavra bacana: %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", 67, 65, 82, 65, 76, 72, 79, 83, 32, 65, 76, 65, 68, 79, 83);  
printf("              %c%c%c%c%c             %c%c%c%c%c            %c%c%c%c%c", 56, 61, 61, 61, 68, 56, 61, 61, 61, 68, 56, 61, 61, 61, 68);


    return 0;
}