#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>


int main()
{
    char nome[15][50],r,nome2[50];
    float v[15][4],media1=0,media2=0;
    int x,y;
    for(x=0;x<2;x++)
    {
       printf("digite o nome do %d aluno: ",x+1);
       scanf("%s",nome[x]);
       printf("digite as notas:\n");
       for(y=1;y<=3;y++)
       {
          printf("p%d: ",y);
          scanf("%f",&v[x][y]);
          if (y==3)
          {
             for(y=1;y<=3;y++)
             {
                media1=media1+v[x][y];
             }
          v[x][4]=media1/3.0;
          media1=0;
          }
       }
       media2=media2+v[x][4];
    }
    printf("a media dos alunos ao total eh = %.2f\n\n",media2/x);
    while(r!=110)
    {
       printf("deseja saber a media de um aluno em especial?(s/n)\n");
       scanf("%c",&r);
       if(r==115)
       {
          printf("digite o nome: ");
          scanf("%s",nome2);
          for(x=0;strcmp(nome[x],nome2)!=0;x++);
          printf("%.2f\n",v[x][4]);
       }
    }
          
       
    system("PAUSE");
    return EXIT_SUCCESS;
}
