#include <constream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

class Relogio{
  private:
    int seg, min, hor;
  public:
    void setHora(int segundos, int minutos, int horas);
    void coutHora();
    void Relogio :: avancando();
};

    void Relogio :: setHora(int segundos, int minutos, int horas){
      seg=segundos;
      min=minutos;
      hor=horas;
    }

    void Relogio :: coutHora(){
      cout<<hor<<":"<<min<<":"<<seg;
    }

    void Relogio :: avancando(){
      while (hor<24){
	seg++;
	if(seg>=60){
           min++;
	  // min=seg/60;
	   seg=(seg%60);
	 }

	 if (min>=60){
           hor++;
	  // hor=min/60;
	   min=(min%60);
	 }
	 getch();
	 cout<<"\t"<<hor<<":"<<min<<":"<<seg;
      }
    }//end void avancar


  void main(){
    clrscr();
    int s=0, m=0, h=0;
    Relogio x;
    cout<<"\tDigite as horas, minutos e segundo respectivamente";
    cin>>h>>m>>s;
    x.setHora(s, m, h);
    x.coutHora();
    x.avancando();
    getch();
}