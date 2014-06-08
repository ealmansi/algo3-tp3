#include "cacm.h"
#include "cacm_goloso.h"
#include "cacm_busq_local.h"
using namespace cacm;
using namespace cacm_busq_local;

#include <iostream>
#include <list>
#include <vector>
using namespace std;

typedef list<int> li;
typedef vector<bool> vb;

/*    *    *    *    *    *    *    *    *    *    *    *    */

salida cacm_busq_local::resolver(const entrada& e)
{
  salida s_golsoso = cacm_goloso::resolver(e);
  if (not s_golsoso.hay_solucion)
    return s_golsoso;

  leje& ejes = s_golsoso.ejes;
  int W1 = s_golsoso.W1, W2 = s_golsoso.W2;

  bool seguir_buscando = true;
  while (seguir_buscando)
  {
    seguir_buscando = false;
  }

  return s_golsoso;
}
