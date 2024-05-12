#include <stdio.h>
#include <stdlib.h>


int main() 
{
   float a, b, m;

   printf("Digite dois numeros:\n");
   scanf("%f %f", &a, &b);

   m = (a+b)/2;

   printf("A sua media eh: %2.0f", m);  
   
   return 0;
}
