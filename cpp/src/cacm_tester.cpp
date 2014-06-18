#include "cacm.h"
#include "cacm_exacto.h"
#include "cacm_goloso.h"
#include "cacm_busq_local.h"
#include "cacm_grasp.h"
using namespace cacm;

#include <iostream>
#include <cstdlib>
#include <set>
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

entrada generar_instancia_aleatoria(int n, int m, int max_w1, int max_w2, int K)
{
  entrada e;
  e.n = n;
  e.m = m;
  e.u = (rand() %  e.n) + 1;
  do { e.v = (rand() %  e.n) + 1; } while (e.u == e.v);
  e.K = K;
  e.adyacentes.resize(e.n + 1);

  int u, v;
  set<int> ejes; set<int>::iterator it;
  
  while (ejes.size() < e.m)
  {
    u = (rand() %  e.n) + 1;
    do { v = (rand() %  e.n) + 1; } while (u == v);
    ejes.insert(u * (e.n + 1) + v);
  }

  for (it = ejes.begin(); it != ejes.end(); ++it)
  {
    u = (*it) / (e.n + 1);
    v = (*it) % (e.n + 1);
    int w1 = (rand() % max_w1) + 1;
    int w2 = (rand() % max_w2) + 1;
    e.adyacentes[u].push_back(ady(v, w1, w2));
    e.adyacentes[v].push_back(ady(u, w1, w2));
  }

  for (int i = 1; i < e.n + 1; ++i)
    e.adyacentes[i].sort(comparar_ady_por_v);

  return e;
}

int main(int argc, char const *argv[])
{
  for (int i = 0; i < 5; ++i)
  {
    // entrada e = grafo_rompe(4000);
    entrada e = generar_instancia_aleatoria(30, 300, 100, 100, 150);

    salida s;

    cout << "exacto" << endl;
    s = cacm_exacto::resolver(e);
    escribir_salida(s);
    cout << endl;

    cout << "goloso" << endl;
    s = cacm_goloso::resolver(e);
    escribir_salida(s);
    cout << endl;

    cout << "busq_local" << endl;
    s = cacm_busq_local::resolver(e);
    escribir_salida(s);
    cout << endl;

    cout << "grasp" << endl;
    s = cacm_grasp::resolver(e);
    escribir_salida(s);
    cout << endl;

    cout << "---------------" << endl;
  }

  return 0;
}
