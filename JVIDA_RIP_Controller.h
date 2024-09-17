//JVIDA-RIP - Controller.h
//09/10/2023
//Grupo: RIP
//pedro yoshissaro / Isadora Piloto / Rafael Cabral 


int EscolherDim();
void ApresentaMatriz();
void LimpaTela();
void MenuPrincipal();
void EscolherMatriz();
void LimparBuffer();
void AddCelulas();
void CriaMatriz();
void MostraOuEsconde();
int MostraOuNao = 2;
void LimparMesa();
void Simulacao();
void Atraso();
void MostrarCelulasMortas();
void NaoMostraVizinho();
void MostraMatriz();
void GerarProxima();
int ContarVizinhosVivos(int x, int y);
void iniciaListas();
void carregaVivo(int ii, int jj);
void mostraLvivo();
void carregaVivoProx(int ii, int jj);
bool VerifMorto(int ii, int jj);
void carregaMorto(int ii, int jj);
void excluiLVivo(int ii, int jj);
void carregaMortosViz();
void atualizaViz();
void liberaLista(TipoCel *aux, int tot);
void alocamem();
void salvarGeracoesEmArquivo();
void carregarGeracoesDeArquivo();