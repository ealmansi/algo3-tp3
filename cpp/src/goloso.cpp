#include "cacm.h"
#include "cacm_goloso.h"
using namespace cacm;
using namespace cacm_goloso;

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
