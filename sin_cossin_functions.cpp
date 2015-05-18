#include <stdlib.h>
#include <stdio.h>

float pot(float teta,int p);   //calculo exponencial
int fatorial(int fat);         //calculo fatorial
float seno(float teta);        //sen
float cos(float teta);         //cos

int main()
{
    int p=7;
    float teta;
    printf("Digite um angulo em radianos.\n\n");
    scanf("%f",&teta);
    printf("\nsen(%f) = %f",teta,seno(teta));
    printf("\ncos(%f) = %f",teta,cos(teta));
    printf("\n\n");
    system("PAUSE");
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
