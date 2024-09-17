//JVIDA-RIP - Model.h
//09/10/2023
//Grupo: RIP
//pedro yoshissaro / Isadora Piloto / Rafael Cabral 


int dim; // dimensao escolhida pelo criador
char Matriz[60][60];
int atraso;
char MatrizAux[60][60];
#define FALSE 0
#define TRUE 1
#define VIVO 'O'
#define MORTO '.'
#define VIZINHO '+'
int *pontx;

bool fviz = FALSE; 