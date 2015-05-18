/*
  Nome:Rodrigo Noronha Menezes Kreutz 
  P.P.E.E. 
  Engenharia Eletrica-Eletronica
  Professor: Jeferson Dalmonte 
  Data: 05/06/12 21:15
  Descricao:Trabalho de numeros complexos. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{//estrutura criada.
    double a,b;
} complex;

complex soma(complex z1, complex z2);
complex subtr(complex z1, complex z2);
complex mult(complex z1, complex z2);
complex divi(complex z1, complex z2);
double modulo(complex z);
double angle(complex z);
void mostra(complex z);
complex le(void);

int main()
{
  complex z1,z2;
  printf("Digite o primeiro numero complexo:\n");
  z1=le();   //z1 e igual ao valor retornado pela funcao.
  printf("\n\nDigite o segundo numero complexo:\n");
  z2=le();
  printf("\n\nSoma: ");
  mostra(soma(z1,z2)); //mostra usa como argumento a funcao.
  printf("\nSubtracao: ");
  mostra(subtr(z1,z2));
  printf("\nMultiplicacao: ");
  mostra(mult(z1,z2));
  printf("\nDivisao: ");
  mostra(divi(z1,z2));
  printf("\nModulo do primeiro numero complexo: %.3lf",modulo(z1));
  printf("\nModulo do segundo numero complexo: %.3lf\n\n",modulo(z2));
  printf("\nAngulo de fase do primeiro numero complexo: %.3lf",angle(z1));
  printf("\nAngulo de fase do segundo numero complexo: %.3lf\n\n",angle(z2));
  
  system("PAUSE");	
  return 0;
}

complex le(void)
{
   complex z;                    //A funcao pede para digitar dois numeros
   printf("Parte real: ");       //e esses numeros ficam armazenados na
   scanf("%lf",&z.a);            //estrutura z que a funcao retorna.
   printf("Parte imaginaria: ");
   scanf("%lf",&z.b);
   return z;
}
   
void mostra(complex z)
{
   if(z.b<0&&z.a!=0) //se o b for negativo ele plota direto (- b)
   {                 //porque sem isso ficaria (+ -b).
      z.b=z.b*(-1.0);    
      printf("%.3lf - %.3lf * i\n\n",z.a,z.b);
   }
   else if(z.a==0&&z.b!=0)//caso a seja 0 apenas o b aparece.
      printf("%.3lf * i\n\n",z.b);
   else if(z.b==0&&z.a!=0)//caso b seja 0 apenas o a aparece.
      printf("%.3lf\n\n",z.a);
   else if(z.a==0&&z.b==0)//caso ambos sejam 0 o resultado e 0.
      printf("0\n\n");
   else//qualquer outra condicao ele mostra a + b.
      printf("%.3lf + %.3lf * i\n\n",z.a,z.b);
}

complex soma(complex z1, complex z2)
{
   z1.a=z1.a+z2.a;//soma os elementos de mesma natureza.
   z1.b=z1.b+z2.b;
   return z1;
}

complex subtr(complex z1, complex z2)
{
   z1.a=z1.a-z2.a;//subtrai elementos de mesma natureza
   z1.b=z1.b-z2.b;
   return z1;
}

complex mult(complex z1, complex z2)
{
   complex z;//multiplicacao de numeros complexos
   z.a=(z1.a*z2.a)-(z1.b*z2.b);
   z.b=(z1.a*z2.b)+(z2.a*z1.b);
   return z;
}

complex divi(complex z1, complex z2)
{
   complex z;//divisao de numeros complexos
   z.a=((z1.a*z2.a)+(z1.b*z2.b))/(pow(z2.a,2)+pow(z2.b,2));
   z.b=((z2.a*z1.b)-(z1.a*z2.b))/(pow(z2.a,2)+pow(z2.b,2));
   return z;
}

double modulo(complex z)//calcula modulo.
{
   return sqrt(pow(z.a,2)+pow(z.b,2));
}

double angle(complex z)//calculo o angulo de fase.
{
   return atan2(z.b,z.a);
}
