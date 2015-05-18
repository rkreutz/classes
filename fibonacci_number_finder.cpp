/*
  Nome: Rodrigo Noronha Menezes Kreutz 
  Turma: 450
  Cadeira: Projeto e Planejamento para Eletrônica
  Curso: Engenharia Elétrica-Eletrônica
  Professor: Jeferson Dalmonte
  Data: 10/05/12
  Descrição: A serie de fibonacci calculada por funcao recursiva e não recursiva.
*/
#include <stdio.h>
#include <stdlib.h>

long fibonacci(long n);             //pelo modo recursivo

int main()
{
  long n;
  printf("Digite o termo da serie de fibonacci: ");
  scanf("%ld",&n);
  
  
  //pelo modo recursivo
  
  printf("\n\n\n(Metodo recursivo) - O valor do termo e : %ld",fibonacci(n)); 
  
  
  //modo nao recursivo
         
  long x,fib[n];  //fib[n] seria um vetor cotendo todos os valores da serie com o ultimo
                  //termo sendo o termo digitado pelo pessoa no computador. 
  for(x=0;x<=n;x++)
  {
      if(x==0) fib[x]=0;            //a posicao 0 e a 1 do vetor tem valor 0 e 1 respec-
      else if(x==1) fib[x]=1;       //tivamente e as proximas posicoes serao o resultado
      else fib[x]=fib[x-1]+fib[x-2];//da soma das ultimas duas posicoes.
  }
  printf("\n\n\n(Metodo nao recursivo) - O valor do termo e : %ld\n\n",fib[n]); //imprime o ultimo termo da serie 
                                                       //calculada.
          
  
  
  
  system("PAUSE");	
  return 0;
}

long fibonacci(long n)              //pelo modo recursivo
{
     if(n==0) return 0;      //funcao retorna valor 0.
     else if(n==1) return 1; //funcao retorna valor 1.
     else return fibonacci(n-1)+fibonacci(n-2); 
     /*funcao retorna a soma dos dois ultimos termos sendo que caso esses dois numeros nao sejam 0 ou 1 ira criar um loop na funcao, dessa forma ocorrera apenas uma soma de zeros e uns.*/
}
