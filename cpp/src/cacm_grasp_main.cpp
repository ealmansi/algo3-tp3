#include "cacm.h"
#include "cacm_grasp.h"
using namespace cacm;
using namespace cacm_grasp;


int main(int argc, char const *argv[])
{
  entrada e;
  while (leer_instancia_listas_ordenadas(e))
  {
    salida s = resolver(e);
    escribir_salida(s);
  }

  return 0;
}
