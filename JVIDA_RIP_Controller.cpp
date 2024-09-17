//JVIDA-RIP - controller
//09/10/2023
//Grupo: RIP
//pedro yoshissaro / Isadora Piloto / Rafael Cabral

#include <stdio.h>
#include <stdlib.h>
#include "JVIDA_RIP_Controller.h"
#include "JVIDA_RIP_View.cpp"
#include <time.h>

void EscolherMatriz()
{
	EscolherDim();
	CriaMatriz();
}

void MenuPrincipal()
{
	int esco;
	do
	{
		esco = ChamarMenu();
		switch(esco)
		{
			case 1:
				ApresentaMatriz();
				break;
			case 2:
				LimparMesa();
				break;
			case 3:
				AddCelulas();
				break;
			case 4:
				MostraOuEsconde();
				break;
			case 5:
				Simulacao();
				break;
			case 6:
				salvarGeracoesEmArquivo();
				apresentaMensagem("Jogo salvo com sucesso");
                break;
            case 7: 
            	carregarGeracoesDeArquivo();
            	apresentaMensagem("Jogo recuperado com sucesso");
            	break;
            case 8:
            	MostraRegras();
            	break;
			case 0:
				apresentaMensagem("Obrigado por jogar");
				break;
			default:
				apresentaMensagem("Opcao invalida, tente novamente\n");
		}
	}while(esco != 0);
	
}

int EscolherDim()
{
	do
	{
		apresentaMensagem("\nEscolha o tamanho da matriz(10 - 60): ");
		scanf("%d", &dim);
			
		if(dim >= 10 && dim <= 60)
		{
			return dim;
		}
			
		else
		{
			apresentaMensagem("Tamanho invalido, tente novamente!");
			LimpaTela();
		}
			
	
	}while(dim< 10 || dim > 60);

}

void MostrarCelulasMortas()
{
	int i, j;
	
		for (i = 1; i <= dim; i++) 
		{
	        for (j = 1; j <= dim; j++) 
			{
	            if (Matriz[i][j] == 'O') 
				{
	                if (Matriz[i - 1][j] != 'O')   // Verifica se a posicao acima eh valida "Logica utilizada, caso nao seja 'O', vai ser '+'" 
						Matriz[i - 1][j] = '+';
	                
	                if (Matriz[i + 1][j] != 'O')  // Verifica se a posicao abaixo eh valida
	                    Matriz[i + 1][j] = '+';
	                
	                if (Matriz[i][j - 1] != 'O')  // Verifica se a posicao a esquerda eh valida
	                    Matriz[i][j - 1] = '+';
	                
	                if (Matriz[i][j + 1] != 'O')   // Verifique se a posicao a direita eh valida
	                    Matriz[i][j + 1] = '+';
	                
	                if ( Matriz[i - 1][j - 1] != 'O') // Verifique se a posicao superior esquerda eh valida
	                    Matriz[i - 1][j - 1] = '+';
	                
	                if (Matriz[i - 1][j + 1] != 'O')  // Verifica se a posicao superior direita eh valida
	                    Matriz[i - 1][j + 1] = '+';
	                
	                if (Matriz[i + 1][j - 1] != 'O') // Verifica se a posicao inferior esquerda eh valida
	                    Matriz[i + 1][j - 1] = '+';
	                
	                if ( Matriz[i + 1][j + 1] != 'O')  // Verifica se a posicao inferior direita eh valida
	                    Matriz[i + 1][j + 1] = '+';
	            }
	        }
	    }
	    
}

void NaoMostraVizinho()
{
	int i, j;
	
	for (i = 1; i <= dim; i++)
	    {
	        for (j = 1; j <= dim; j++)
	        {
	            if (Matriz[i][j] == 'O')
	            {
	                if (Matriz[i - 1][j] == '+')   // Verifica se a posicao acima eh valida
						Matriz[i - 1][j] = '.';
	                
	                if (Matriz[i + 1][j] == '+')  // Verifica se a posicao abaixo eh valida
	                    Matriz[i + 1][j] = '.';
	                
	                if (Matriz[i][j - 1] == '+')  // Verifica se a posicao a esquerda eh valida
	                    Matriz[i][j - 1] = '.';
	                
	                if (Matriz[i][j + 1] == '+')   // Verifique se a posicao a direita eh valida
	                    Matriz[i][j + 1] = '.';
	                
	                if ( Matriz[i - 1][j - 1] == '+') // Verifique se a posicao superior esquerda eh valida
	                    Matriz[i - 1][j - 1] = '.';
	                
	                if (Matriz[i - 1][j + 1] == '+')  // Verifica se a posicao superior direita eh valida
	                    Matriz[i - 1][j + 1] = '.';
	                
	                if (Matriz[i + 1][j - 1] == '+') // Verifica se a posicao inferior esquerda eh valida
	                    Matriz[i + 1][j - 1] = '.';
	                
	                if ( Matriz[i + 1][j + 1] == '+')  // Verifica se a posicao inferior direita eh valida
	                    Matriz[i + 1][j + 1] = '.';
	            }
	        }
	    }
}

void MostraMatriz()
{
    int i, j;

    printf("  ");
    for (j = 1; j <= dim; j++) 
        printf(" %2d ", j);
    printf("\n");

    for (i = 1; i <= dim; i++)
    {
        printf("%2d", i); 
        for (j = 1; j <= dim; j++)
        {
            printf("  %c ", Matriz[i][j]);
        }
        printf("\n");
    }

    // Coordenadas das celulas vivas
    printf("\nCoordenadas das celulas vivas:\n");
    for (i = 1; i <= dim; i++)
    {
        for (j = 1; j <= dim; j++)
        {
            if (Matriz[i][j] == 'O')
            {
                printf("(%d,%d) ", i, j);
            }
        }
    }
    printf("\n");

    // Coordenadas dos vizinhos mortos
    printf("\nCoordenadas dos vizinhos mortos:\n");
    for (i = 1; i <= dim; i++)
    {
        for (j = 1; j <= dim; j++)
        {
            if (Matriz[i][j] != 'O')
            {
                int vizinhosVivos = ContarVizinhosVivos(i, j);

                
                if (vizinhosVivos == 2 || vizinhosVivos == 3)
                {
                    printf("(%d,%d) ", i, j);
                }
            }
        }
    }
    printf("\n");

    MostraLvivo();
    MostraLmorto();
}




void ApresentaMatriz()
{
	int i, j;
	
	if(MostraOuNao == 1)
	{
		MostrarCelulasMortas();
		MostraMatriz();
		
	}
	
	if(MostraOuNao == 2)
	{
		NaoMostraVizinho();
		MostraMatriz();
	}
    
}

void AddCelulas()
{
	int i, j, sen, esc, op, l, c;
	
	do
	{
		ApresentaMatriz();
		Menuzinho();
		scanf("%d", &sen);
		
		switch(sen)
		{
			case 1: 
					apresentaMensagem("-----------------------------------------\n");
					apresentaMensagem("Digite as coordenadas desejadas\n");
					apresentaMensagem("Digite a linha desejada( -1 para voltar): ");
					scanf("%d", &i);
					if(i == -1)
					{
						break;
					}
					apresentaMensagem("Digite a coluna desejada: ");
					scanf("%d", &j);
					
					
					if( i > dim || i == 0 || j > dim || j == 0)
					{
						LimpaTela();
						apresentaMensagem("\nCoordenada digitada invalida, tente novamente!\n\n");
						break;
					}
					
					if(Matriz[i][j] == 'O')
			 		{
			 			LimpaTela();
				 		apresentaMensagem("Coordenada ja esta ocupada\n");
				 		break;
					}
					
					else if(Matriz[i][j] == '.')
					{
						Matriz[i][j] = 'O';
						LimpaTela();
						apresentaMensagem("Celula adicionada\n");
						break;
			 		}
			 		
			 		else if(Matriz[i][j] == '+')
			 		{
						Matriz[i][j] = 'O';
						LimpaTela();
						apresentaMensagem("Celula adicionada\n");
						break;
						
					
			 		}
					
			case 2:
				apresentaMensagem("Digite as coordenadas desejadas\n");
				apresentaMensagem("Digite a linha desejada (-1 para voltar): ");
				scanf("%d", &l);
				if( l == -1)
				{
					break;
				}
				apresentaMensagem("Digite a coluna desejada: ");
				scanf("%d", &c);
				
				if( l > dim || l == 0 || c > dim || c == 0)
				{
					LimpaTela();
					apresentaMensagem("Coordenada digitada invalida, tente novamente\n\n");
					break;
				}
				
				if(Matriz[l][c] == '.')
			 	{
			 		LimpaTela();
			 		apresentaMensagem("Nao existe celula para ser excluida\n\n");
			 		break;
				}
				
				else if (Matriz[l][c] == 'O')
	            {
	                //Antes de remover a celula, remover as celulas mortas vizinhas
	                if (Matriz[l - 1][c] == '+')
	                    Matriz[l - 1][c] = '.';
	                if (Matriz[l + 1][c] == '+')
	                    Matriz[l + 1][c] = '.';
	                if (Matriz[l][c - 1] == '+')
	                    Matriz[l][c - 1] = '.';
	                if (Matriz[l][c + 1] == '+')
	                    Matriz[l][c + 1] = '.';
	                if (Matriz[l - 1][c - 1] == '+')
	                    Matriz[l - 1][c - 1] = '.';
	                if (Matriz[l - 1][c + 1] == '+')
	                    Matriz[l - 1][c + 1] = '.';
	                if (Matriz[l + 1][c - 1] == '+')
	                    Matriz[l + 1][c - 1] = '.';
	                if (Matriz[l + 1][c + 1] == '+')
	                    Matriz[l + 1][c + 1] = '.';
	
	                
	                Matriz[l][c] = '.';
	
	                LimpaTela();
	                apresentaMensagem("Celula excluida com sucesso!!\n\n");
	                break;

	            }

			
			default:
				LimpaTela();
				apresentaMensagem("Opcao Invalida, tente novamente!\n\n");
		}	
	}while(sen != 0);
	LimpaTela();
}

void CriaMatriz()
{
	int i, j;
	for(i = dim; i >= 1; i--)
        for(j = 1; j <= dim; j++)
            Matriz[i][j] = '.';
}

void CriarAux()
{
	int i, j;
	for(i = dim; i >= 1; i--)
        for(j = 1; j <= dim; j++)
            MatrizAux[i][j] = '.';
}

void LimpaTela()
{
	system("@cls||clear");
}

void LimparBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void LimparMesa()
{
	int esco;
	
	Menuzinho3();
	scanf("%d", &esco);
	
	if(esco == 1)
	{
		CriaMatriz();
		LimpaTela();
		apresentaMensagem("Mesa Limpada com sucesso!\n");
	}
	
	if(esco == 2)
	{
		LimpaTela();
		apresentaMensagem("Operacao cancelada!\n");
	}
}

void MostraOuEsconde()
{ 
	int opcao;
    Menuzinho2();
    scanf("%d", &opcao);
    
    if(opcao == 1)
    {
    	MostraOuNao = 1;
    	apresentaMensagem("Celulas mortas vizinhas serao mostradas\n");
	}
	if(opcao == 2)
	{
		MostraOuNao = 2;
		apresentaMensagem("Celulas mortas vizinhas nao serao mostradas\n");
	}
	
	if(opcao == 0)	
	{
		LimpaTela();
		apresentaMensagem("Nenhuma Opcao Escolhida!\n");
	}
	
}

void Simulacao()
{
	int continuar, geracao, atraso, esc;
	
	Menuzinho5();
	scanf("%d", &esc );
	
	
	if(esc == 1)
	{
		do
		{
			Menuzinho6();
			scanf("%d", &continuar);
			
			if(continuar == 1)
			{
				GerarProxima();
				LimpaTela();
				ApresentaMatriz();
			}
		}while(continuar != 0);
		
		LimpaTela();
	}
	
	else if(esc == 2)
	{
		Menuzinho4();
		scanf("%d %d", &geracao, &atraso);
		
		for(int i = 0; i < geracao; i++)
		{
			GerarProxima();
			LimpaTela();
			ApresentaMatriz();
			
			time_t lt1, lt2;
			//atraso de tempo
			lt1 = time(NULL);
			lt2 = lt1;
			while (difftime(lt2, lt1) < atraso)
			{
				lt2 = time(NULL);
			}
				
		}
	}
	
	else if(esc == 0)
		apresentaMensagem("Saindo...");
	
	else
		apresentaMensagem("Opcao invalida");
}

void GerarProxima() 
{
    int i, j;
    char MatrizTemp[dim+2][dim+2];  // Matriz temporaria para guardar a proxima geracao

    for (i = 1; i <= dim; i++) {
        for (j = 1; j <= dim; j++) {
            int vizinhosVivos = ContarVizinhosVivos(i, j);

            // Aplicar as regras do Jogo da Vida
            if (Matriz[i][j] == 'O') {
                if (vizinhosVivos < 2 || vizinhosVivos > 3) 
				{
                    MatrizTemp[i][j] = '.';  // Celula morre
                } 
				
				else 
				{
                    MatrizTemp[i][j] = 'O';  // Celula continua viva
                }
            } 
			else 
			{
                if (vizinhosVivos == 3) 
				{
                    MatrizTemp[i][j] = 'O';  // Celula nasce
                } 
				
				else 
				{
                    MatrizTemp[i][j] = '.';  // Celula permanece morta
                }
            }
        }
    }

    // Copia a matriz temporária de volta para a matriz principal
    for (i = 1; i <= dim; i++) 
	{
        for (j = 1; j <= dim; j++) 
		{
            Matriz[i][j] = MatrizTemp[i][j];
        }
    }
}


int ContarVizinhosVivos(int linha, int coluna) 
{
    int vizinhosVivos = 0;

    for (int i = linha - 1; i <= linha + 1; i++) 
	{
        for (int j = coluna - 1; j <= coluna + 1; j++) 
		{
            if ((i != linha || j != coluna) && i >= 1 && i <= dim && j >= 1 && j <= dim) 
			{
                if (Matriz[i][j] == 'O') {
                    vizinhosVivos++;
                }
            }
        }
    }

    return vizinhosVivos;
}

void carregaVivo(int ii, int jj)
{
	TipoCel *aux = (TipoCel*)malloc(sizeof(TipoCel));
	
	if (aux == NULL)
	{
		apresentaMensagem("Sem espaco na memoria para inclusao de celula viva\n");
		return;
	}
	
	aux->lin = ii; 
	
	aux->col = jj;
	if(totvivo == 0) 
	{
		pvivo = aux;
		pvivo->next = NULL; 
	
	}
	
	else 
	{
		aux->next = pvivo; 
		pvivo = aux; 
	 }
	 
	 totvivo++; 
}

void carregaVivoProx(int ii, int jj)
{
	 TipoCel *aux = (TipoCel*)malloc(sizeof(TipoCel));
	 if (aux == NULL)
	 {
		apresentaMensagem("Sem espaco na memoria para inclusao de celula viva para a proxima geracao\n");
		return;
	 }
	 aux->lin = ii;
	 aux->col = jj;
	 if(totvivoprox == 0) 
	 {
		 pvivoprox = aux;
		 pvivoprox->next = NULL;
	 }
	 else 
	 {
		 aux->next = pvivoprox;
		 pvivoprox = aux; 
	 }
	 
	 totvivoprox++;
}

bool VerifMorto(int ii, int jj)
{
	 TipoCel *aux;
	 aux = pmorto;
	 if (totmorto == 0)
	 	return FALSE;
	 do
	 {
		 if (aux->lin == ii && aux->col == jj)
		 return TRUE;
		 aux = aux->next;
	 } while (aux != NULL);
	 
	 return FALSE;
}

void carregaMorto(int ii, int jj)
{
	 if ((ii < 0) || (jj < 0)) 
	 	return;
	 if ((ii >= dim) || (jj >=dim)) 
	 	return;
	 if(MatrizAux[ii][jj] == VIVO) 
	 	return;
	 
	 if (VerifMorto(ii, jj)== TRUE)
	 	return;
	 
	 TipoCel *aux = (TipoCel*)malloc(sizeof(TipoCel));
	 if (aux == NULL)
	 {
		 apresentaMensagem("Sem espaco na memoria para inclusao de celula morta-vizinha\n");
		 return;
	 }
	 
	 aux->lin = ii;
	 aux->col = jj;
	 if(totmorto == 0) 
	 {
		 pmorto = aux;
		 pmorto->next = NULL;
	 }
	 else 
	 {
		 aux->next = pmorto;
		 pmorto = aux; 
	 }
	 totmorto++;
	 if (fviz == TRUE) 
	 	MatrizAux[ii][jj] = VIZINHO;
	 else
	 	MatrizAux[ii][jj] = MORTO;
}

void carregaMortosViz()
{
	 int k, i, ii, jj;
	 struct
	 {
	 	int li, co;
	 } a,b,c,d,e,f,g,h; 
	 
	 totmorto = 0;
	 TipoCel *aux;
	 aux = pvivo;
	 if (totvivo == 0)
		 return;
	 do
	 {
		 ii = aux->lin;
		 jj = aux->col;
		 a.li = ii-1; a.co = jj-1;
		 b.li = ii-1; b.co = jj;
		 c.li = ii-1; c.co = jj+1;
		 d.li = ii; d.co = jj-1;
		 e.li = ii; e.co = jj+1;
		 f.li = ii+1; f.co = jj-1;
		 g.li = ii+1; g.co = jj;
		 h.li = ii+1; h.co = jj+1;
		 carregaMorto(a.li, a.co);
		 carregaMorto(b.li, b.co);
		 carregaMorto(c.li, c.co);
		 carregaMorto(d.li, d.co);
		 carregaMorto(e.li, e.co);
		 carregaMorto(f.li, f.co);
		 carregaMorto(g.li, g.co);
		 carregaMorto(h.li, h.co);
		 if(aux->next == NULL)
		 	break;
		 aux = aux->next;
	 }while(TRUE);
}

void atualizaViz()
{
	 int i, j, ii, jj, vii, vjj, ct;
	 liberaLista(pvivoprox, totvivoprox);
	 pvivoprox = NULL; 
	 if (pvivo == NULL)
	 	return;
	 
	 TipoCel *aux, *aux2;
	 aux = pvivo;
	 do
	 {
		 ct = 0; 
		 ii = aux->lin;
		 jj = aux->col;
		 aux2 = pvivo;
		 do
		 {
			 vii = aux2->lin;
			 vjj = aux2->col;
			 if (vii != ii || vjj != jj) 
			 	if(abs(ii-vii)<=1 && abs(jj-vjj)<=1) 
			 		ct++;
			 aux2 = aux2->next;
		 } while(aux2 != NULL);
		 
		 if (ct == 2 || ct == 3)
		 	carregaVivoProx(ii,jj); 
		 
		 aux = aux->next;
	 } while(aux != NULL);
	 if (pmorto == NULL)
	 	return;
	 
	 aux = pmorto;
	 do
	 {
		 ct = 0; 
		 ii = aux->lin;
		 jj = aux->col;
		 aux2 = pvivo;
		 do
		 {
			 vii = aux2->lin;
			 vjj = aux2->col;
			 if(abs(ii-vii)<=1 && abs(jj-vjj)<=1) 
			 	ct++;
			 aux2 = aux2->next;
		 } while(aux2 != NULL);
		 
		 if (ct == 3)
		 	carregaVivoProx(ii,jj); 
		 aux = aux->next;
	 } while(aux != NULL);
}

void excluiLVivo(int ii, int jj)
{
	 TipoCel *aux, *aux2; 
	 aux = pvivo;
	 aux2 = aux; 
	 if (totvivo > 0)
	 {
		 while (aux->lin != ii || aux->col != jj)
		 {
			 aux2 = aux;
			 aux = aux->next;
		 }
		 
		 if (aux->lin == ii && aux->col == jj)
		 {
			 if (aux2 == aux) 
			 	pvivo = aux->next;
			 else
			 	aux2->next = aux->next;
			 free(aux);
		}
		 totvivo--;
	 }
}

void liberaLista(TipoCel *aux, int tot)
{
	if(aux == NULL || tot == 0) //já está liberada
		return;
	TipoCel *aux2;
	do
	{
		aux2 = aux;
		aux = aux->next;
		free(aux2); //libera memoria
	}
	while(aux != NULL);
}

void alocamem()
{
	aux = (TipoCel*)malloc(sizeof(TipoCel));
	if (aux == NULL)
	 {
		 apresentaMensagem("Sem espaco na memoria\n");
		 return; 
 	}
}

void iniciaListas()
{
	 liberaLista(pvivo, totvivo);
	 liberaLista(pmorto, totmorto);
	 liberaLista(pvivoprox, totvivoprox);
	 pvivo = pmorto = pvivoprox = NULL; 
	 totvivo = totmorto = totvivoprox = 0; 
}

void salvarGeracoesEmArquivo()
 {
    FILE *arquivo;
    arquivo = fopen("geracoes_salvas.txt", "w");

    if (arquivo == NULL) 
	{
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivo, "%d\n", dim);  

    for (int i = 1; i <= dim; i++) 
	{
        for (int j = 1; j <= dim; j++) 
		{
            fprintf(arquivo, "%c ", Matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}
void carregarGeracoesDeArquivo() 
{
    FILE *arquivo;
    arquivo = fopen("geracoes_salvas.txt", "r");

    if (arquivo == NULL) 
	{
        fprintf(stderr, "Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    fscanf(arquivo, "%d", &dim);  // Lê a dimensão da matriz

    for (int i = 1; i <= dim; i++) 
	{
        for (int j = 1; j <= dim; j++)
		{
            fscanf(arquivo, " %c", &Matriz[i][j]);
        }
    }

    fclose(arquivo);
}

