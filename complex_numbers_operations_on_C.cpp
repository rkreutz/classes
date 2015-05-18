#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
    float num[2][2];
    printf("Digite o numero complexo:\n");
    scanf("%f",&num[1][1]);
    printf("+ i*");
    scanf("%f",&num[1][2]);
    printf("Digite o segundo numero para realizar as funcoes matematicas:\n");
    scanf("%f",&num[2][1]);
    printf("+ i*");
    scanf("%f",&num[2][2]);
    printf("Primeiro = %.1f+%.1f*i\nSegundo = %.1f+%.1f*i\n",num[1][1],num[1][2],num[2][1],num[2][2]);
    printf("soma = %.2f + %.2f*i\n",num[1][1]+num[2][1],num[1][2]+num[2][2]);
    printf("subtracao = %.2f + %.2f*i\n",num[1][1]-num[2][1],num[1][2]-num[2][2]);
    printf("multiplicacao = %.2f + %.2f*i\n",(num[1][1]*num[2][1])-(num[2][2]*num[1][2]),(num[1][1]*num[2][2])+(num[1][2]*num[2][1]));
    printf("divisao = %.2f + %.2f*i\n",(num[1][1]*num[2][1]-(-1.0)*num[2][2]*num[1][2])/(pow(num[2][1],2)+pow(num[2][2],2)),(num[1][1]*(-1.0)*num[2][2]+num[1][2]*num[2][1])/(pow(num[2][1],2)+pow(num[2][2],2)));
    
    
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
