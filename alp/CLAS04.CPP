#include <constream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

class Relogio{
  private:
    int hor, min, seg;
    int *ptrh;
    int *ptrm;
    int *ptrs;
  public:
    void setHora(int h, int m, int s);
    void getHora(int &ho, int &mi, int &se);
    void avancando();
};

  void Relogio :: setHora(int h, int m, int s){
    hor=h;
    min=m;
    seg=s;
    cout<<"\t"<<hor<<":"<<min<<":"<<seg<<"\n\n\n\n";
  }

  void Relogio :: getHora(int &ho, int &mi, int &se){
    ptrh=&hor;
    ho=(*ptrh);
    ptrm=&min;
    mi=(*ptrm);
    ptrs=&seg;
    se=(*ptrs);
  }

  void Relogio :: avancando(){
    while(hor<24){
      seg++;
      if(seg>=60){
	min++;
	seg=(seg-60);
      } //end if
      if (min>=60){
	hor++;
	min=(min-60);
      } //end if
    cout<<hor<<":"<<min<<":"<<seg;
    getch();
    }    //end while
    cout<<"pao";
   }

void main(){
  clrscr();
  int w, y, z;
  Relogio x;
  x.setHora(10,50,19);
  x.getHora(w, y, z);
  x.avancando();
  cout<<w<<":"<<y<<":"<<z;
  getch();
}
