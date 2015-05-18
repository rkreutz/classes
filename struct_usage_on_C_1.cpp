#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



int main()
{
    int x,y=3,z;
   struct inf
   {
          float imc,peso,altura;
          int anos;
          char nome[80];
   };
   
   typedef struct inf alunos;
   alunos aluno[y];
   for(x=0;x<y;x++)
   {
          printf("Digite o nome do %d aluno: ",x+1);
          gets(aluno[x].nome);
   }
   for(x=0;x<y;x++)
   {
          printf("Digite o peso de %s: ",aluno[x].nome);
          scanf("%f",&aluno[x].peso);
          printf("Digite a altura de %s: ",aluno[x].nome);
          scanf("%f",&aluno[x].altura);
          printf("Digite a idade de %s: ",aluno[x].nome);
          scanf("%d",&aluno[x].anos);
          aluno[x].imc=aluno[x].peso/pow(aluno[x].altura,2);
   }
   while(x!=0)
   {
      printf("1 - Media de idades\n2 - Media dos IMCs\n3 - Maior IMC\n4 - Menor IMC\n5 - Aluno mais velho\n6 - Aluno mais novo\n0 - Encerra o programa\n");
      scanf("%d",&x);
      if(x==1)
      {
              int mediai=0;
              for(x=0;x<y;x++)
              {
                          mediai=mediai+aluno[x].anos;
              }
              printf("%d anos\n",mediai/(y));
              x=9;
      }
      if(x==2)
      {
              float somai=0;
              for(x=0;x<y;x++)
              {
                              somai=somai+aluno[x].imc;
              }
              printf("%.2f\n",somai/(y));
              x=9;
      }
      if(x==3)
      {
              float mimc=0;
              for(x=0;x<y;x++)
              {
                              if(mimc<aluno[x].imc) 
                              {
                                                    mimc=aluno[x].imc;
                                                    z=x;
                              }
              }
              printf("%s\n",aluno[z].nome);
              x=9;
      }
      if(x==4)
      {
              float Mimc=0;
              for(x=0;x<y;x++)
              {
                              if(Mimc>aluno[x].imc) 
                              {
                                                    Mimc=aluno[x].imc;
                                                    z=x;
                              }
              }
              printf("%s\n",aluno[z].nome);
              x=9;
      }
      if(x==5)
      {
                            int idadeM=0;
              for(x=0;x<y;x++)
              {
                              if(idadeM<aluno[x].anos) 
                              {
                                                    idadeM=aluno[x].anos;
                                                    z=x;
                              }
              }
              printf("%s\n",aluno[z].nome);
              x=9;
      }
      if(x==6)
      {
                               int idadem=0;
              for(x=0;x<y;x++)
              {
                              if(idadem>aluno[x].anos) 
                              {
                                                    idadem=aluno[x].anos;
                                                    z=x;
                              }
              }
              printf("%s\n",aluno[z].nome);
              x=9;
      }
   }
    system("PAUSE");
    return EXIT_SUCCESS;
}
