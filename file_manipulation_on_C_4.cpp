#include <stdio.h>
#include <stdlib.h>

int main()
{
  float vect[3]={0,0,0};
  float f;
  FILE *pFile;
  
  pFile = fopen ("arquivo.txt","w+"); 
  fprintf (pFile, "%2.2f %2.2f %2.2f", 3.1416, 55.3, 56.4);
  printf ("\nEu escrevi na primeira linha do arquivo:\n\n%2.2f %2.2f %2.2f\n\n", 3.1416, 55.3, 56.4);
  
  
  fclose (pFile); // Aponta para o começo do arquivo
  pFile = fopen ("arquivo.txt","a+");
  fscanf(pFile, "%f %f %f", &vect[0], &vect[1], &vect[2]);
  printf ("\nEu li na primeira linha do arquivo:\n\n %2.2f, %2.2f and %2.2f\n",vect[0], vect[1], vect[2]);
  
  rewind (pFile); // Aponta para o começo do arquivo
  fprintf (pFile, "\n%2.2f %2.2f %2.2f", 3.1416*2, 55.3*2, 56.4*2);
  printf ("\nEu escrevi na segunda linha do arquivo:\n\n%2.2f %2.2f %2.2f\n\n", 3.1416*2, 55.3*2, 56.4*2);

  rewind (pFile); // Aponta para o começo do arquivo
  fscanf(pFile, "\n%f %f %f", &vect[3], &vect[4], &vect[5]);
  printf ("\n\nEu li na segunda linha do arquivo:\n\n %2.2f, %2.2f and %2.2f\n",vect[3], vect[4], vect[5]);
  
  printf("\n\n");
  fclose (pFile);	
  system("PAUSE");
  return 0;
}
