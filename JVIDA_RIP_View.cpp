//JVIDA-RIP - View
//09/10/2023
//Grupo: RIP
//pedro yoshissaro / Isadora Piloto / Rafael Cabral 


#include "JVIDA_RIP_View.h"

void apresentaMensagem(char mens[100])
{
	printf("%s", mens);
}

int ChamarMenu() //menu de uso 
{
	int op;
	printf("\n\n");
	printf("+--------------------------------------+\n");
    printf("|             JOGO DA VIDA            |\n");
    printf("+--------------------------------------+\n");
    printf("|             Menu Geral:             |\n");
    printf("+--------------------------------------+\n");
    printf("| 1 - Apresentar Mapa                 |\n");
    printf("| 2 - Limpar Mesa                     |\n");
    printf("| 3 - Incluir/Excluir celulas         |\n");
    printf("| 4 - Mostrar/Esconder vizinhos mortos|\n");
    printf("| 5 - Iniciar Processo                |\n");
    printf("| 6 - Gravar uma geracao inicial      |\n");
    printf("| 7 - Recuperar geracao cadastrada    |\n");
    printf("| 8 - Regras do jogo                  |\n");
    printf("| 0 - Sair                            |\n");
    printf("+--------------------------------------+\n");
    printf("Escolha uma opcao: ");
	scanf("%d", &op);
	LimpaTela();
	printf("\n");
	return op;
}

void Menuzinho()
{
	printf("+--------------------------------------+\n");
    printf("|             Menu                    |\n");
    printf("+--------------------------------------+\n");
    printf("| 1 - Adicionar Celula                |\n");
    printf("| 2 - Remover Celula                  |\n");
    printf("| 0 - Sair                            |\n");
    printf("+--------------------------------------+\n");
    printf("Escolha uma opcao: ");
	
	
}

void Menuzinho2()
{
	printf("+--------------------------------------+\n");
    printf("|             Menu                    |\n");
    printf("+--------------------------------------+\n");
    printf("| 1 - Mostrar Vizinhos                |\n");
    printf("| 2 - Esconder Vizinhos               |\n");
    printf("| 0 - Sair                            |\n");
    printf("+--------------------------------------+\n");
    printf("Escolha uma opcao: ");
}

void Menuzinho3()
{
	printf("+--------------------------------------+\n");
    printf("|       Deseja Limpar a Mesa?         |\n");
    printf("+--------------------------------------+\n");
    printf("| 1 - sim                             |\n");
    printf("| 2 - nao                             |\n");
    printf("+--------------------------------------+\n");
    printf("Escolha uma opcao: ");
}

void Menuzinho4()
{
	printf("+--------------------------------------+\n");
    printf("|         Configuracoes               |\n");
    printf("+--------------------------------------+\n");
    printf("| Digite a quantidade de geracoes     |\n");
    printf("| Digite o atraso de tempo            |\n");
    printf("+--------------------------------------+\n");
    printf("Digite as opcoes (x y): ");
}

void Menuzinho5()
{
	printf("+--------------------------------------+\n");
    printf("|         Configuracoes               |\n");
    printf("+--------------------------------------+\n");
    printf("| 1 - Fazer geracoes manualmente      |\n");
    printf("| 2 - Simulacao automatica            |\n");
    printf("| 0 - Sair                            |\n");
    printf("+--------------------------------------+\n");
    printf("Digite a opcao:  ");
}
void Menuzinho6()
{
	printf("+--------------------------------------+\n");
    printf("|         Configuracoes               |\n");
    printf("+--------------------------------------+\n");
    printf("| Deseja fazer a proxima geracao?     |\n");
    printf("| 0 - Nao / 1 - Sim                   |\n");
    printf("+--------------------------------------+\n");
    printf("Digite a opcao:  ");
}

void MostraLvivo()
{
	int c=0;
	TipoCel *aux;
	aux=pvivo;
	if(totvivo>0)
	{
		printf("Celulas vivas: ");
		while(aux->next!=NULL)
		{
			printf("(%d,%d)  ",aux->lin,aux->col);
			aux=aux->next;
			c++;
			if(c%10==0)
				printf("\n\t\t\t ");
			
		}
		printf("(%d,%d)\n",aux->lin,aux->col);
	}
	printf("\n");
}


void MostraLmorto()
{
	int c=0;
	TipoCel *aux;
	aux=pmorto;
	if(totmorto>0)
	{
		printf("Celulas mortas-vizinhas: ");
		while(aux->next!=NULL)
		{
			printf("(%d,%d)  ",aux->lin,aux->col);
			aux=aux->next;
			c++;
			if(c%10==0)
				printf("\n\t\t\t ");
		}
		printf("(%d,%d)  ",aux->lin,aux->col);
	}
	printf("\n\n");
}

void MostraRegras()
{
	printf("+--------------------------------------+\n");
	printf("|         Regras do Jogo da Vida        |\n");
	printf("+--------------------------------------+\n");
	printf("| O Jogo da Vida  eh um                |\n");
	printf("| automato celular com regras simples  |\n");
	printf("| que geram padroes complexos.         |\n");
	printf("|                                      |\n");
	printf("| Regras:                              |\n");
	printf("| 1. Uma celula viva com 2 ou 3        |\n");
	printf("|    vizinhos vivos sobrevive.         |\n");
	printf("| 2. Uma celula morta com exatamente   |\n");
	printf("|    3 vizinhos vivos se torna viva.   |\n");
	printf("| 3. Morte por solidao: uma celula     |\n");
	printf("|    viva com menos de 2 vizinhos      |\n");
	printf("|    vivos morre.                      |\n");
	printf("| 4. Morte por superpopulacao: uma     |\n");
	printf("|    celula viva com mais de 3         |\n");
	printf("|    vizinhos vivos morre.             |\n");
	printf("|                                      |\n");
	printf("| Explore as dinamicas e padroes       |\n");
	printf("| interessantes gerados pelo Jogo da   |\n");
	printf("| Vida. Divirta-se!                    |\n");
	printf("+--------------------------------------+\n");

}