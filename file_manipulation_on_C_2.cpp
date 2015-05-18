#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
    FILE *pfile;
    char c[100],k='a';
    int x;
    printf("1 - Criar agenda.\n2 - Editar agenda existente.\n3 - Abrir agenda.\n4 - Fechar programa\n");
    while(x!=4)
    {
       printf("Operacao: ");
       gets(c);
       x=atoi(c);
       if(x==1)
       {
          printf("Digite o nome da agenda: ");
          gets(c);
          pfile=fopen(c,"w");
          while(x!=0)
          {
             printf("Nome: ");
             gets(c);
             fputs("     ",pfile);
             fputs(c,pfile);
             fputs("\n",pfile);
             printf("Endereco: ");
             gets(c);
             fputs(" Endereco: ",pfile);
             fputs(c,pfile);
             fputs("\n",pfile);
             printf("Telefone: ");
             gets(c);
             fputs(" Telefone: ",pfile);
             fputs(c,pfile);
             fputs("\n",pfile);
             printf("Deseja adicionar outro contato?(1 - sim/0 - nao)");
             gets(c);
             x=atoi(c);
          }          
          fclose(pfile);
       }
       if(x==2)
       {
          printf("Digite o nome da agenda: ");
          gets(c);
          pfile=fopen(c,"a");
          if(pfile!=NULL)
          {
          while(x!=0)
          {
             printf("Nome: ");
             gets(c);
             fputs("     ",pfile);
             fputs(c,pfile);
             fputs("\n",pfile);
             printf("Endereco: ");
             gets(c);
             fputs(" Endereco: ",pfile);
             fputs(c,pfile);
             fputs("\n",pfile);
             printf("Telefone: ");
             gets(c);
             fputs(" Telefone: ",pfile);
             fputs(c,pfile);
             fputs("\n",pfile);
             printf("Deseja adicionar outro contato?(1 - sim/0 - nao)");
             gets(c);
             x=atoi(c);
          }          
          }
          else printf("Arquivo nao existe\n");
          fclose(pfile);
       }
       if(x==3)
       {
          printf("Digite o nome do arquivo: ");
          gets(c);
           pfile=fopen(c,"r");
           if(pfile!=NULL)
           {
              k=0;
              while(k!=EOF)
              {
                 k=fgetc(pfile);
                 if(k!=EOF)
                 {
                    fgets(c,100,pfile);
                    printf("%s",c); 
                 }
              }
           }
           else printf("\narquivo nao existe");
           fclose(pfile);
       }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
