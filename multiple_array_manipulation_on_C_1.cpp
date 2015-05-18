#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define alunos 5                 //qntos alunos sao
#define cadeiras 6               //qntas cadeiras sao
#define avaliacoes 3             //qntas avaliacoes sao
int main()
{
    float nota[alunos][cadeiras][avaliacoes],g1[alunos][cadeiras],sg1=0,soma=0,g1g[alunos],maior=0;
    int x,y,z;
    char aluno[alunos][80],cadeira[cadeiras][80],consulta[80],menu;
    srand(time(NULL));
    for(x=0;x<alunos;x++)
    {
       for(y=0;y<cadeiras;y++)
       {
          for(z=0;z<avaliacoes;z++)
          {
             nota[x][y][z]=((rand()%71)/10.0)+3.0;
             sg1=sg1+nota[x][y][z];
          }
          g1[x][y]=sg1/avaliacoes;
          sg1=0;
          soma=soma+g1[x][y];
       }
       g1g[x]=soma/cadeiras;
       soma=0;
    }
    printf("Digite os nomes dos alunos:\n");
    for(x=0;x<alunos;x++)
    {
       gets(aluno[x]);
    }
    printf("Digite as cadeiras dos coitados:\n");
    for(x=0;x<cadeiras;x++)
    {
       gets(cadeira[x]);
    }
    printf("\nA - Listar as medias de cada disciplina de um determinado aluno.\n\
B - Listar quais disciplinas determinado aluno passa por media.\n\
C - Listar quais disciplinas determinado aluno pega G2.\n\
D - Listar quais disciplinas determinado aluno nao e aprovado.\n\
E - Listar qual e o nome do aluno melhor qualificado\n\
S - Sair do programa.\n\n");
    while(menu!='s')
    {
       gets(&menu);
       if(menu=='A'||menu=='a')
       {
          printf("Digite o nome: ");
          gets(consulta);
          for(x=0;x<alunos;x++)
          {
             if(strcmp(consulta,aluno[x])==0)
             {
                for(y=0;y<cadeiras;y++)
                {
                   printf("Media de %s = %2.1f\n",cadeira[y],g1[x][y]);
                }
             }
          }
       } 
       if(menu=='B'||menu=='b')
       {
          printf("Digite o nome: ");
          gets(consulta);
          for(x=0;x<alunos;x++)
          {
             if(strcmp(consulta,aluno[x])==0)
             {
                for(y=0;y<cadeiras;y++)
                {
                   if(g1[x][y]>=7.0) printf("%s\n",cadeira[y]);
                }
             }
          }
       }
       if(menu=='C'||menu=='c')
       {
          printf("Digite o nome: ");
          gets(consulta);
          for(x=0;x<alunos;x++)
          {
             if(strcmp(consulta,aluno[x])==0)
             {
                for(y=0;y<cadeiras;y++)
                {
                   if(g1[x][y]<7.0&&g1[x][y]>=4.0) printf("%s\n",cadeira[y]);
                }
             }
          }
       }
       if(menu=='D'||menu=='d')
       {
          printf("Digite o nome: ");
          gets(consulta);
          for(x=0;x<alunos;x++)
          {
             if(strcmp(consulta,aluno[x])==0)
             {
                for(y=0;y<cadeiras;y++)
                {
                   if(g1[x][y]<4.0) printf("%s\n",cadeira[y]);
                }
             }
          }
       }
       if(menu=='E'||menu=='e')
       {
          for(x=0;x<alunos;x++)
          {
             if(maior<g1g[x]) 
             {
                maior=g1g[x];
                z=x;
             }
          }
          printf("%s foi o melhor qualificado com %.1f\n",aluno[z],g1g[z]);
       }
       printf("\n\n");
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
