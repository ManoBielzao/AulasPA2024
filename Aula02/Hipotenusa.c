#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Hipo(double cat1, double cat2)
{         
    double hip;
    
    hip = sqrt((pow(cat1,2))+(pow(cat2,2)));
    
    return hip;
}

void ExibInfo(double cat1, double cat2, double hip)
{
   printf("Um cateto eh: %lf\n", cat1);
   printf("O outro cateto eh: %lf\n", cat2);
   printf("A sua hipotenusa eh: %lf\n", hip);
}

int main() 
{
    double a, b, h;
    
    printf("Digite 2 catetos:\n");
    scanf("%lf %lf", &a, &b);
    
    h = Hipo(a,b);
    
    ExibInfo(a,b,h);

    return 0;
    
}

