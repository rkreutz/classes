/*
  Nome: Rodrigo N. M. Kreutz
  P.P.E.E.
  Professor Jeferson Dalmonte
  Data: 26/06/12 21:23
  Descricao: Trabalho 5 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define mk 1.609343
#define total 365*24


void leArquivo(int *prm, float *v);
float calculaMedia(float v[total]);
float calculaDesv(float v[total], float media);
void histograma(float v[total], int *hist);
void plotaMatlab(int *hist);


void main()
{
    int prm,hist[80]={};
    float v[total]={},media;
    leArquivo(&prm,v);
    if(prm==1)
    {
       media=calculaMedia(v);
       printf("Media da velocidade do vento no ano de 1991: %f km/h\n\n",media);
       printf("Desvio da velocidade do vento no ano de 1991: %f km/h\n\n",calculaDesv(v,media));
       histograma(v,hist);
       plotaMatlab(hist);
    }
    system("PAUSE");
}


void leArquivo(int *prm, float *v)
{
    FILE *pfile;
    int x=0,y,dia,mes,ano;
    float valor;
    pfile = fopen("wind.txt","r");
    if (pfile!=NULL)
    {
        *prm=1;
        for(;x<12;x++)
        {
           fscanf(pfile,"%d %d %d",&mes,&ano,&dia);
           for(y=0;y<24*dia;y++)
           {
              fscanf(pfile," %f,",&valor);
              *v=valor*mk;
              *v++;
           }
        }
    }
    else
    {
        *prm=0;
        printf("\n\nArquivo nao encontrado.\n\n");
    }
}


float calculaMedia(float v[total])
{
    int k;
    float soma=0;
    for(k=0;k<total;k++)
        soma+=v[k];
    //printf("%f",v[k-1]);
    return soma/(total);
}


float calculaDesv(float v[total], float media)
{
    int k;
    float soma=0,desvio=0;
    for (k=0;k<total;k++)
        soma += pow(v[k] - media,2);
    desvio = sqrt(soma/((total)-1));
    return desvio;
}


void histograma(float v[total], int *hist)
{
     int k,x;
     float min,max;
     for(k=0;k<80;k++)
     {
         max = 0.25 + (0.5*k);
         if (k==0) 
             min = 0;
         else 
             min = (0.5*k) - 0.25;
         for(x=0;x<total;x++)
         {
             if (v[x]>=min&&v[x]<max)
                 *hist+=1;
         }
         hist++;
     }
}


void plotaMatlab(int *hist)
{
    FILE *pr;
    int k;
    pr = fopen("desenha.m", "w");
    fprintf(pr, "hist =[ \n");
    for(k=0; k<80; k++)
    fprintf(pr,"%d \n", hist[k]);
    fprintf(pr,"];\n");
    fprintf(pr,"figure\n");
    fprintf(pr,"vento = 0:0.5:39.5;\n");
    fprintf(pr,"stem(vento, hist);\n");
    fprintf(pr,"xlabel('Velocidade do Vento em km/h');\n");
    fprintf(pr,"title('Histograma')\n");
    fclose(pr);
}
