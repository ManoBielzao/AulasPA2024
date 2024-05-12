#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define PI 3.1415

int main ()
{
    const float PI1 = 3.1415;
    double r;
    double circ, area;
    printf("Digite o valor do raio do circulo: \n");
    scanf("%lf", &r);
    circ = 2*PI*r;
    area = PI*(pow(r,2));
    printf("Sua area eh: %lf\n", area);
    printf("Sua circuferencia eh: %lf\n", circ);


    return 0;
}