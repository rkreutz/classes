#include <cstdlib>
#include <iostream>
#include <stdio.h>
int celsius(float x)
{
    printf("Digite a temperatura (em graus Celsius):");
    scanf("%f",&x);
    printf("Em graus Farenheit = %.3f\n\n\n",32+1.8*x);
}
int farenheit(float x)
{
    printf("Digite a temperatura (em graus Farenheit):");
    scanf("%f",&x);
    printf("Em graus Celsius = %.3f\n\n\n",(x-32)/1.8);
}

int main()
{
    int a;
    printf("Qual a unidade da sua temperatura, Farenheit ou Celsius?(F/f ou C/c)");
    scanf("%c",&a);
    if(a==70||a==102) farenheit(a);
    if(a==67||a==99) celsius(a);
    system("PAUSE");
    return EXIT_SUCCESS;
}
