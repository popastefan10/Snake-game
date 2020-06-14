#include "../Headers/Harta.h"

Harta::Harta()
{
    //ctor
}

Harta::Harta(string numeFisier){
  ifstream in(numeFisier);
  in>>n>>m;
  width = n;
  length = m;
  for(int i = 0; i < n; i++){/// indexez de la 0 ca sa fie pozitiile ok cu cele din snake
    for(int j = 0; j < m; j++){
      char caracter;
      in>>caracter;
      if(caracter == '#')
        perete[i][j] = true;
      else
        perete[i][j] = false;
    }
  }
}

void Harta::displayHarta(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(perete[i][j]){
        gotoXY(j,i);
        cout<<"#";
      }
    }
  }
}

bool Harta::estePerete(int x,int y){
  return perete[y][x];
}
