#include <constream.h>

int main(void){
  float altura=0, maior=0, menor=3, media=0;
  int qtd_f=0, fem=0, masc=0;
  char sexo;
  clrscr();
  for(int i=0; i<5; i++){
    cout<<"\n\tQual sua altura?";
    cin>>altura;
    if (altura>maior)
      maior=altura;
    if (altura<menor)
      menor=altura;
    cout<<"\n\tQual seu sexo? (f/m)";
    cin>>sexo;
    if (sexo=='f'){
      fem=fem+altura;
      qtd_f++;
    }
    if (sexo=='m')
      masc++;
  }//---end of for
  media=(float)fem/(float)qtd_f;

  cout<<"\n\n\n\tA menor altura e': "<<menor;
  cout<<"\tA maior altura e': "<<maior;
  cout<<"\tA media das mulheres e': "<<media;
  cout<<"\tO numero de homens e': "<<masc;
  getch();
  return 0;
}


