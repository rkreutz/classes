#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *pfile;
    char escrito[80];
    int x,y;
    char c;
    printf("1 - escrever nomes dos alunos em um arquivo\n\
2 - ler nomes dos alunos de um arquivo\n3 - sair\n");
    while(y!=3)
    {
       printf("Operacao: ");
       scanf("%d",&y);
       if(y==1)
       {
          printf("Digite o nome do seu arquivo: ");
          scanf("%s",escrito);
          pfile=fopen(escrito,"w+");
          printf("Digite o nome dos 15 alunos:\n");
          for(x=0;x<15;x++)
          {
             scanf("%s",escrito);
             fputs(escrito,pfile);
             fputs("\n",pfile);
          }
          fclose(pfile);
       }
       if(y==2)
       {
          printf("Digite o nome do arquivo: ");
          scanf("%s",escrito);
          pfile=fopen(escrito,"r");
          if(pfile!=NULL)
          {while(c!=EOF)
          {
             c=fgetc(pfile);
             if(c!=EOF) printf("%c",c);
          }
          }
          else printf("Arquivo nao encontrado\n");
          fclose(pfile);
          
       }
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
