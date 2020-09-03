#include <constream.h>

void main(void) {
  float altura=0.0, maior=0.0, menor=3.0, media=0.0, fem=0.0, masc=0.0;
  char sexo;
  for (int i=1; i<=5; i++) {
    clrscr();
    cout << "\n\tDigite uma altura : ";
    cin >> altura;
    cout << "\n\tDigite o sexo? (f/m) : ";
    cin >> sexo;
    if (altura>maior)
      maior=altura;
    if (altura<menor)
      menor=altura;
    if (sexo=='m')
      masc++;
    if (sexo=='f') {
      fem++;
      media=media+altura;
    } //----end of if
  } //----end of for
  media=media/fem;
  cout << "\n\n\n\tA menor altura do grupo e' : " << menor;
  cout << "\n\tA maior altura do grupo e' : " << maior;
  cout << "\n\tA media de altura das mulheres e' : " << media;
  cout << "\n\tO numero de homens e' : " << masc;
  getch();
}