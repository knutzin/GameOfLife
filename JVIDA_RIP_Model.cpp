//JVIDA-RIP - Model
//09/10/2023
//Grupo: RIP
//pedro yoshissaro / Isadora Piloto / Rafael Cabral 

#include "JVIDA_RIP_Model.h"

typedef struct cel
{
     int lin, col; 
     struct cel *next; 
} TipoCel;


TipoCel *aux;
TipoCel *pvivo, *pmorto, *pvivoprox;
int totvivo, totmorto, totvivoprox;
