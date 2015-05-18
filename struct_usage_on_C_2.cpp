#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct addr {
char name[30];
char street[40];
char city[20];
char state[3];
unsigned long int zip;
} addr_info[MAX];//declara��o de matriz de estruturas

void init_list(void);
void enter(void);
void delete2(void);
void list(void);
int menu_select(void);
int find_free(void);

int main(void)
{
   char choice;
   init_list(); // inicializa a matriz de estruturas
   for(;;) {
      choice=menu_select(); //Seleciona as op��es do usu�rio
      switch(choice) { //testa a op��o escolhida
      case 1: enter();//solicita dados do usu�rio
      break;
      case 2: delete2();
      break;
      case 3: list();
      break;
      case 4: exit(0);
      }
   }
}

void init_list(void)
{
    register int t;
    for(t=0; t<MAX; ++t) addr_info[t].name[0] = '\0';
}

/* Obt�m a sele��o escolhida pelo usu�rio */
int menu_select(void)
{
    char s[80];
    int c;
    printf("1. Inserir um nome\n");
    printf("2. Excluir um nome\n");
    printf("3. Listar o arquivo\n");
    printf("4. Sair\n");
    do {
         printf("\nEntre com sua escolha: ");
         gets(s);
         c = atoi(s);
        } while(c<0 || c>4);
    return c;
} 

/* Encontra uma estrutura nao usada. */
int find_free(void)
{
   register int t;
   for(t=0; addr_info[t].name[0] && t<MAX; ++t);
   if(t==MAX) return -1; /* nenhum elemento livre */
   return t;
}

/* Insere os endere�os na lista */
void enter(void)
{
   int slot;
   char s[80];
   slot = find_free();
   if(slot==-1) {
       printf("\nlista cheia");
       return;
   }
   printf("entre o nome: ");
   gets(addr_info[slot].name);
   printf("entre a rua: ");
   gets(addr_info[slot].street);
   printf("entre a cidade: ");
   gets(addr_info[slot].city);
   printf("entre o estado: ");
   gets(addr_info[slot].state);
   printf("entre o cep: ");
   gets(s);
   addr_info[slot].zip = strtoul(s, '\0', 10);
}

/* Apaga um endere�o */
void delete2(void)
{
    register int slot;
    char s[80];
    printf("entre o registro #: ");
    gets(s);
    slot = atoi(s);
    if(slot>=0 && slot < MAX)
       addr_info[slot].name[0] = '\0';
}

/* Mostra a lista na tela. */
void list(void)
{
    system("cls");
    register int t;
    for(t=0; t<MAX; ++t) {
        if(addr_info[t].name[0]) {
           printf("Nome: %s\n", addr_info[t].name);
           printf("Rua: %s\n", addr_info[t].street);
           printf("Cidade: %s\n", addr_info[t].city);
           printf("Estado: %s\n", addr_info[t].state);
           printf("ZIP: %lu\n\n", addr_info[t].zip);
         }
    }
    printf("\n\n");
}
