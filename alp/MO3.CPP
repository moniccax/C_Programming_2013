#include <constream.h>

void main(){
  clrscr();
  float alt, maior=0.0, menor=3.0, media, alt_m;
  int homens=0.0, mulheres=0.0;
  char sexo;
  for (int i=0; i<5; i++){
    cout<<"Digite a altura: "<<endl;
    cin>>alt;
    if (alt>maior)
      maior=alt;
    if (alt<menor)
      menor=alt;
    cout<<"Digite o sexo: (f/m) "<<endl;
    cin>>sexo;
    if (sexo=='f'){
      mulheres++;
      alt_m+=alt;
    }
    if (sexo=='m')
      homens++;
   }
  media=alt_m/(float)mulheres;
  cout<<"A media da altura das mulheres e'"<<media<<endl;
  cout<<"A maior altura e': "<<maior<<". A menor e':"<<menor<<endl;
  cout<<"O numero de homens e': "<<homens;
  getch();
}



