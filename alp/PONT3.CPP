#include <constream.h>

int main(){
  int x=5, y=2;
  int *px, *py;

  px=&x;

  py=&y;

  if (px<py)
    cout << "py-px : " << (py-px) << endl;
  else
    cout << "px-py : " << (px-py) << endl;

  cout << "px: " << px;
  cout << " - *px: " << *px;
  cout << " - &px: " << &px << endl;

  *px=(*px)+2;
  cout << "px: " << px;
  cout << " - *px: " << *px;
  cout << " - &px: " << &px << endl << endl;

  cout << "py: " << py;
  cout << " - *py: " << *py;
  cout << " - &py: " << &py << endl;
  (*py)++;

  cout << "py: " << py;
  cout << " - *py: " << *py;
  cout << " - &py: " << &py;

  getch();
  return 0;
}
