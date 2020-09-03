#include <constream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct tv{
  char canal[255];
  int volume;
};

class tele{
  private:
    tv televisao[255];
  public:
    tele();
    void procuraCanal(char c[222]);
    void vol(int atual, int quero);
};

  tele :: tele(){
    int i;
    for (i=0; i<=10; i++)
      televisao[i].volume=i;
    strcpy(televisao[0].canal, "disney");
    strcpy(televisao[1].canal, "globo");
    strcpy(televisao[2].canal, "warner");
    strcpy(televisao[3].canal, "cnn");
  }//end tele::tele()

  void tele :: procuraCanal(char c[222]){
    int i=0;
    while  (strcmp(televisao[i].canal, c) !=0)
      i++;
    cout<<"O canal selecionado e: "<< televisao[i].canal <<endl;
    if (strcmp(televisao[i].canal, c) !=0)
      i=1;
  }//end tele::procuracanal

   void tele :: vol(int atual, int quero){
     int i;
     for (i=atual; i<=quero; i++)
       televisao[i].volume;
     cout<<"Volume e'"<<televisao[i-1].volume;
   }//end tele::vol

void main(){
  clrscr();
  tele x;
  x.procuraCanal("warner");
  x.vol(2,7);
  getch();
}