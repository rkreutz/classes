#include <stdio.h>
#include <stdlib.h>
#define max 629
float pot(float teta,int p);//calculo exponencial
int fatorial(int fat);//calculo fatorial
float seno(float teta);//sen
float cos(float teta);     //cos
void plotaMatlab(float dados[max][4]);//plota graficos

int main()
{
    float dados[max][4],ang[max],sen[max],cs[max],tang[max];
    int x;
    char c;
    printf("  angulo  |   seno   |    cos   |   tang\n");
    for(x=0;x<max;x++)
    {
        ang[x]=(x/100.0)-3.14;
        dados[x][0]=ang[x];
        sen[x]=seno(ang[x]);
        dados[x][1]=sen[x];
        cs[x]=cos(ang[x]);
        dados[x][2]=cs[x];
        tang[x]=sen[x]/cs[x];
        dados[x][3]=tang[x];
        printf("  %5.2f   |  %6.3f  |  %6.3f  |  %.3f\n",dados[x][0],dados[x][1],dados[x][2],dados[x][3]);
        if(x==157||x==313||x==471)
        {
            printf("\nPara mostrar a outra parte da tabela pressione enter.");
            gets(&c);
            system("cls");
            printf("  angulo  |   seno   |    cos   |   tang\n");
        }
        else if(x==max-1)
        {
            printf("\nPressione enter para encerrar o programa");
            scanf("%c",&c);
        }
    }
    plotaMatlab(dados);
    return 0;
}
//sen
float seno(float teta)
{
      float seno=0;
      int n;
      for(n=0;n<6;n++)
          seno=seno+(pot(teta,2*n+1)*pot(-1,n)/fatorial(2*n+1));
      return seno;
}
//cos
float cos(float teta)
{
      int n;                    
      float cos=0;
      for(n=0;n<7;n++)
          cos=cos+(pot(teta,2*n)*pot(-1,n)/fatorial(2*n));
      return cos;
}
//calculo exponencial
float pot(float teta,int p)
{
    float pot=1;
    for(;p>0;p--)
        pot=pot*teta;
    return pot;   
}
//calculo fatorial
int fatorial(int fat)
{
    int x;                    
    if(fat==0)                
        fat=1;
    else
        for(x=fat;x>1;x--)
            fat=fat*(x-1);
    return fat;
}

void plotaMatlab(float dados[max][4])
{
     FILE *pr; int k;
     pr=fopen("trigonometria.m","w");
     fprintf(pr,"dados =[ \n");
     for(k=0;k<max;k++)
     fprintf(pr,"%.2f %.5f %.5f %.5f \n",dados[k][0],dados[k][1],dados[k][2],dados[k][3]);
     fprintf(pr,"];\n");
     fprintf(pr,"figure(1)\n");
     fprintf(pr,"plot(dados(:,1)*180/pi, dados(:,2));\n");
     fprintf(pr,"xlabel('Angulo em graus');\n title('Seno')\n grid\n");
     fprintf(pr,"figure(2)\n");
     fprintf(pr,"plot(dados(:,1)*180/pi, dados(:,3));\n");
     fprintf(pr,"xlabel('Angulo em graus');\n title('Cosseno')\n grid\n");
     fprintf(pr,"figure(3)\n");
     fprintf(pr,"plot(dados(:,1)*180/pi, dados(:,4));\n");
     fprintf(pr,"xlabel('Angulo em graus');\n title('Tangente')\n grid\n axis([-200 200 -20 20])");
     fclose(pr);
}

