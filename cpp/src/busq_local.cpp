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

  leje& ejes = s_golsoso.ejes;
  int W1 = s_golsoso.W1, W2 = s_golsoso.W2;

  bool seguir_buscando = true;
  while (seguir_buscando)
  {
    seguir_buscando = false;
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
