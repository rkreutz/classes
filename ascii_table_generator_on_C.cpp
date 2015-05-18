#include <cstdlib>
#include <iostream>
#include <stdio.h>


int main()
{
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned char e;
    printf("\n16 ");
    for(a=16;a<31;a++)
      printf("%c ",a);
    printf("\n32 ");
    for(a=32;a<47;a++)
      printf("%c ",a);
    printf("\n48 ");
    for(a=48;a<63;a++)
      printf("%c ",a);
    printf("\n64 ");
    for(e=64;e<79;e++)
      printf("%c ",e);
    printf("\n80 ");
    for(e=80;e<95;e++)
      printf("%c ",e);
    printf("\n96 ");
    for(e=96;e<111;e++)
      printf("%c ",e);
    printf("\n112 ");
    for(d=112;d<127;d++)
      printf("%c ",d);
    printf("\n128 ");
    for(d=128;d<143;d++)
      printf("%c ",d);
    printf("\n144 ");
    for(d=144;d<159;d++)
      printf("%c ",d);
    printf("\n160 ");
    for(b=160;b<175;b++)
      printf("%c ",b);
    printf("\n176 ");
    for(b=176;b<191;b++)
      printf("%c ",b);
    printf("\n192 ");
    for(c=192;c<207;c++)
      printf("%c ",c);
    printf("\n208 ");
    for(c=208;c<223;c++)
      printf("%c ",c);
    printf("\n224 ");
    for(c=224;c<239;c++)
      printf("%c ",c);
    printf("\n\n");
    
    
    
    int i,j,n;
    for(i=0;i<14;i++)
    {
        n = 16*(i+1);
        printf("%d ",n);
        for(j=0;j<15;j++)
        {
                         printf("%c ",n+j);
}
printf("\n");
}
    
    
    printf("\n\n");
    
    
    
   system("PAUSE");
   return 0;
    
}
