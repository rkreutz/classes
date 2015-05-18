#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int x,y,jogo[6];
    srand(time(NULL));
    for(x=0;x<50;x++)
    {
       
       for(y=0;y<6;y++)
       {
          jogo[y]=rand()%60 + 1;
          printf("%2d  ",jogo[y]);
       }
       printf("\n");
    }
    
    
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
