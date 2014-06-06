#include "cacm.h"
#include "cacm_goloso.h"
using namespace cacm;

#include <iostream>
#include <list>
#include <vector>
using namespace std;

typedef list<int> li;
typedef vector<bool> vb;

/*    *    *    *    *    *    *    *    *    *    *    *    */

salida resolver(const entrada& e)
{
  salida s_golsoso = cacm_goloso::resolver(e);
  if (not s_golsoso.hay_solucion)
    return s_golsoso;

  // int n, m, u, v, K;
  // vlady adyacentes;

  li& camino = s_golsoso.camino;
  int W1 = s_golsoso.W1, W2 = s_golsoso.W2;

  bool seguir_buscando = true;
  while (seguir_buscando)
  {
    li::iterator vi, vj;
    vi = vj = camino.begin();
    ++vj;++vj;

    while (vj != camino.end())
    {
      bool son_adyacentes = false;
      lady::iterator j;
      for (j = e.adyacentes[*vi].begin(); j != e.adyacentes[*vi].end() and not son_adyacentes; ++j)
      {
        if (*j == vj.v)
        {
          son_adyacentes = true;
        }
      }

      ++vi;++vj;
    }
  }

  return s_golsoso;
}

int main(int argc, char const *argv[])
{
  entrada e;
  while(leer_instancia(e))
  {
    salida s = resolver(e);
    escribir_salida(s);
  }

  return 0;
}