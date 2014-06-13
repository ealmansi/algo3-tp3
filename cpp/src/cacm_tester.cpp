#include "cacm.h"
#include "cacm_exacto.h"
#include "cacm_goloso.h"
#include "cacm_busq_local.h"
#include "cacm_grasp.h"
#include <iostream>

using namespace cacm;
using namespace std;

int main(int argc, char const *argv[])
{
  entrada e = grafo_rompe(100);
  salida s = cacm_exacto::resolver(e);
  cout << "Salida exacta: " ;
  escribir_salida(s);
  s = cacm_goloso::resolver(e,100,NULL);
  cout << "Salida golosa: " ;
  escribir_salida(s);
  
  return 0;
}
