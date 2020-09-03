/**********************************
*   FILA_SD.H                     *
***********************************/

const int max=5;
struct tfila {
   int _tfila[max];
};

  int head=-1, // ----- ponteiro para inicio da fila
      tail=0;  // ----- ponteiro para fim da fila
  int* fila = (int*) new tfila;

/*
  if (fila==NULL) {
    cout << "Memoria insuficiente para alocar um inteiro";
    exit(1);
  }
 else { */
// --------------- Funcao enfileira elemento
void enfileira(void) {
  int n;
  // ----- localiza uma posicao vaga no vetor da fila
  if (tail<max) {
    // ----- limpa tela e pede o elemento para enfileirar
    moldura();
    gotoxy(30,3); cout << "Enfileira elemento";
    gotoxy(3,7); cout << "Digite o elemento (n. inteiro) : ";
    cin >> n;
    fila[tail]=n;
    tail++;
  }
  else {
    moldura();
    gotoxy(3, (alt-1));
    cout << "Nao ha espaco livre na fila";
    apito();
  } // ----- else do if (tail<max)
} // ----- enfileira()

// --------------- Funcao desenfileira elemento
void desenfileira(void) {

  int n;
  char ch;
  moldura();
  gotoxy(30,3); cout << "Desenfileira elemento";
  head++;
  if (head<tail) {
    // ----- mostra elemento desenfileirado
    n=fila[head];
    gotoxy(3,8);
    cout << "Elemento retirado da fila : " << n;
    gotoxy(3,(alt-1)); cout << "Tecle <enter> p/ continuar";
    // ----- espera especificamente um enter p/ continuar
    ch=getch();
    while (ch!=13)
     ch=getch();
  }
  else {
    // ----- nao tem elemento para desenfileirar
    head--; // -----para head nao ir ao infinito com sucessivas tentativas
    gotoxy(3, (alt-1));
    cout << "Nao existe elemento para desenfileirar";
    apito();
  }
} // ----- exclui()

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
    getch();
  }
} // ----- mostrafila()

// --------------- Funcao limpa fila
void limpafila(void) {

  int i;
  head=-1, // ----- ponteiro para inicio da fila
  tail=0;  // ----- ponteiro para fim da fila
  for (i=0; i<max; i++)
    fila[i]=0;
} // ----- limpa fila
//}//else

 // delete fila;