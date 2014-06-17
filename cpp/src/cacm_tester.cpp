#include "cacm.h"
#include "cacm_exacto.h"
#include "cacm_goloso.h"
#include "cacm_busq_local.h"
#include "cacm_grasp.h"
using namespace cacm;

#include <iostream>
using namespace std;

entrada grafo_rompe(int i)
{
  entrada e;
  e.n = 5;
  e.m = 6;
  e.u = 1;
  e.v = 5;
  e.K = 2*i;
  e.adyacentes.resize(e.n+1);
  e.adyacentes[1].push_back(ady(2,i+1,1));
  e.adyacentes[2].push_back(ady(1,i+1,1));
  e.adyacentes[1].push_back(ady(3,i,i));
  e.adyacentes[3].push_back(ady(1,i,i));
  e.adyacentes[1].push_back(ady(4,1,i*2));
  e.adyacentes[4].push_back(ady(1,1,i*2));
  
  e.adyacentes[5].push_back(ady(2,i+1,1));
  e.adyacentes[2].push_back(ady(5,i+1,1));
  e.adyacentes[5].push_back(ady(3,i,i));
  e.adyacentes[3].push_back(ady(5,i,i));
  e.adyacentes[5].push_back(ady(4,1,i));
  e.adyacentes[4].push_back(ady(5,1,i));
  
  return e;
}

int main(int argc, char const *argv[])
{
  entrada e = grafo_rompe(400);

  salida s_e = cacm_exacto::resolver(e);
  cout << "Salida exacta: " ;
  escribir_salida(s_e);

  salida s_g = cacm_goloso::resolver(e);
  cout << "Salida golosa: " ;
  escribir_salida(s_g);
  
  return 0;
}
