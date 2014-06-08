#include "cacm.h"
#include "cacm_exacto.h"
using namespace cacm;
using namespace cacm_exacto;


int main(int argc, char const *argv[])
{
  entrada e;
  while (leer_instancia(e))
  {
    salida s = resolver(e);
    escribir_salida(s);
  }

  return 0;
}
