#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>


int main()
{
    FILE *pfile;
    char x,arquivo[80],c;
    printf("Digite C para criar um arquivo ou L para ler um arquivo.('s' finalizar programa)\n");
    
    while(x!='s')
    {
    printf("Operacao: ");
    gets(&x);
    if(x=='C'||x=='c')
    {
       printf("Digite o nome do seu arquivo: ");
       gets(arquivo);
       pfile=fopen(arquivo,"w");
       while(c!='.')
       {
          scanf("%c",&c);
          fputc(c,pfile);
       }
       fclose(pfile);
    }
    
    if(x=='L'||x=='l')
    {
       printf("Digite o nome do arquivo: ");
       gets(arquivo);
       pfile=fopen(arquivo,"r");
       if(pfile!=NULL)
       {
          while(c!=EOF)
          {
             c=fgetc(pfile);
             if(c!=EOF) printf("%c",c);
          }
       }
       else printf("\narquivo nao existe");
       fclose(pfile);
    }
    printf("\n");
    }
    printf("\n\n\n");
    system("PAUSE");
    return EXIT_SUCCESS;
}
