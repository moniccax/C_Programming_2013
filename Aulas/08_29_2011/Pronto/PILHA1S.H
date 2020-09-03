/* --------------- Convencoes para funcionamento da pilha
pilha vazia - topo=0;
pilha cheia - topo=max;
topo e' um ponteiro: pos-incrementado no empilhamento e
		     pre-decrementado no desempilhamento
A pilha cresce (enche) do inicio para o final do vetor
*/

const int max=5;
int topo=0; // ----- ponteiro para inicio da pilha

int pilha[max];


// --------------- Funcao empilha elemento
void empilha(void) {
  int n;
  // ----- localiza uma posicao vaga no vetor da pilha
  if (topo<max) {
    // ----- limpa tela e pede o elemento para empilhar
    moldura();
    gotoxy(30,3); cout << "Empilha elemento";
    gotoxy(3,7); cout << "Digite o elemento (n. inteiro) : ";
    cin >> n;
    pilha[topo]=n;
    topo++;
  }
  else {
    moldura();
    gotoxy(3, (alt-1));
    cout << "Nao ha espaco livre na pilha";
    apito();
  } // ----- else do if (topo<max)
} // ----- empilha()

// --------------- Funcao desempilha elemento
void desempilha(void) {
  int n;
  char ch;
  moldura();
  gotoxy(30,3); cout << "Desempilha elemento";
  if (topo>0) {
    // ----- mostra elemento desempilhado
    topo--;
    n=pilha[topo];
    gotoxy(3,8);
    cout << "Elemento desempilhado : " << n;
    gotoxy(3,(alt-1)); cout << "Tecle <enter> p/ continuar";
    // ----- espera especificamente um enter p/ continuar
    ch=getch();
    while (ch!=13)
     ch=getch();
  }
  else {
    // ----- nao tem elemento para desempilhar
    gotoxy(3, (alt-1));
    cout << "Nao existe elemento para desempilhar";
    apito();
  }
} // ----- desempilha()

// --------------- Funcao Mostra Conteudo da pilha
void mostrapilha(void) {
  int i;
  // ----- limpa tela e percorre vetor mostrando
  //       todo o conteudo da pilha
  moldura();
  gotoxy(30,3); cout << "Mostra pilha";
  gotoxy(3,7); cout << "Topo = " << topo;
  gotoxy(3,(alt-1));
  cout << "Pressione qualquer tecla para rolar a pilha";
  for (i=0; i<max; i++) {
    gotoxy(3,9); cout << "pilha[" << i << "] = " << pilha[i] << endl;
    getch();
  }
} // ----- mostrapilha()

// --------------- Funcao limpa pilha
void limpapilha(void) {
  int i;
  topo=0; // ----- ponteiro para inicio da pilha
  for (i=0; i<max; i++)
    pilha[i]=0;
} // ----- limpa pilha
