// --------------- Declaracao de variaveis globais
#define esc 27

/* --------------- Convencoes para funcionamento da fila
fila vazia - head=max e tail=0
fila esgotada para enfileirar - tail+1=headx
fila sem elementos para desenfileirar - head==tail depois de
  if (head==max) // ----- incremento circular de head
*/
const int max=5;
int head=max, // ----- ponteiro para inicio da fila
    tail=0;  // ----- ponteiro para fim da fila

struct tfila{
  int _tfila[max];
};
int* fila = (int*) new tfila;


// --------------- Funcao enfileira elemento
void enfileira(void) {
  int n;
  // ----- localiza uma posicao vaga no vetor da fila
  if (tail+1==head) {
    moldura();
    gotoxy(3, (alt-1));
    cout << "Nao ha espaco livre na fila";
    apito();
  }
  else {
    // ----- limpa tela e pede o elemento para enfileirar
    moldura();
    gotoxy(30,3); cout << "Enfileira elemento";
    gotoxy(3,7); cout << "Digite o elemento (n. inteiro) : ";
    cin >> n;
    fila[tail]=n;
    tail++;
    if (tail==max) // ----- incremento circular de tail
      tail=0;
  } // ----- else do if (tail<max)
} // ----- enfileira()

// --------------- Funcao desenfileira elemento
void desenfileira(void) {
  int n;
  char ch;
  moldura();
  gotoxy(30,3); cout << "Desenfileira elemento";
  if (head==max) // ----- incremento circular de head
    head=0;
  if (head==tail) {
    // ----- nao tem elemento para desenfileirar
    gotoxy(3, (alt-1));
    cout << "Nao existe elemento para desenfileirar";
    apito();
  }
  else {
    // ----- mostra elemento desenfileirado
    n=fila[head];
    head++;
    gotoxy(3,8);
    cout << "Elemento retirado da fila : " << n;
    gotoxy(3,(alt-1)); cout << "Tecle <enter> p/ continuar";
    // ----- espera especificamente um enter p/ continuar
    ch=tecla();
    while (ch!=13)
     ch=tecla();
  }
} // ----- desenfileira()

// --------------- Funcao Mostra Conteudo da fila
void mostrafila(void) {
  int i;
  // ----- limpa tela e percorre vetor de registro mostrando
  //       dados do funcionario
  moldura();
  gotoxy(30,3); cout << "Mostra fila";
  gotoxy(3,7); cout << "Head = " << head;
  gotoxy(3,8); cout << "Tail = " << tail;
  gotoxy(3,(alt-1));
  cout << "Pressione qualquer tecla para rolar a fila";
  for (i=0; i<max; i++) {
    gotoxy(3,9); cout << "Fila[" << i << "] = " << fila[i] << endl;
    tecla();
  }
} // ----- mostrafila()

// --------------- Funcao limpa fila
void limpafila(void) {
  int i;
  head=max, // ----- ponteiro para inicio da fila
  tail=0;   // ----- ponteiro para fim da fila
  for (i=0; i<max; i++)
    fila[i]=0;
} // ----- limpa fila