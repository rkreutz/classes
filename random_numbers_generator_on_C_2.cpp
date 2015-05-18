#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

        
        
        
        
        
        
        
        
int main()
{
    int R[10],S[10],x,maior,y,z;
    printf("R:\n");
    srand(time(NULL));
    for(x=0;x<10;x++)
    {
       
       
       R[x]=rand()%1000;
       printf("%d\n",R[x]);
    }
    printf("S:\n");
    for(y=9;y>=0;y--)
    {
    maior=0;
    for(x=0;x<10;x++)
    {
       if(maior<R[x]) 
       {
          maior=R[x];
          z=x;
       }
    }
    S[y]=maior;
    R[z]=-1;
    }
    for(x=0;x<10;x++)
    {
       printf("%d\n",S[x]);
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
