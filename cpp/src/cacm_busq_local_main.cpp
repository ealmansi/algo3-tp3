#include "cacm.h"
#include "cacm_busq_local.h"
using namespace cacm;
using namespace cacm_busq_local;


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
