#include <constream.h>

void main(void){
int idade=0, total_idade=-1;
float media;
clrscr();
  do {
    cout<<"Qual sua idade?"<<endl;
    cin>>idade;
    total_idade++;
    media=idade+media;
  } while (idade!=0);

  media=media/total_idade;
  cout<<"A media deste grupo e' : "<<media<<endl;
  getch();
}
