#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y;
    int a;
    printf("Digite um numero: ");
    scanf("%f",&x);
    printf("\nDigite outro numero: ");
    scanf("%f",&y);
    printf("1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\nOu pressione outro numero para fazer nada\n");
    scanf("%d",&a);
    printf("\n");
    switch(a)
    {
       case 1: printf("A soma e %f",x+y); break;
       case 2: printf("A subtracao e %f",x-y); break;
       case 3: printf("A multiplicacao e %f",x*y); break;
       case 4: printf("A divisao e %f",x/y); break;
    }
    printf("\n");
    system("PAUSE");
    return EXIT_SUCCESS;
}
