#include "cacm.h"
#include "cacm_goloso.h"
#include "cacm_busq_local.h"
#include "cacm_grasp.h"
using namespace cacm;
using namespace cacm_grasp;

#define MAX_CANT_IT 1000

double diferencia_relativa(salida& mejor_s, salida& s)
{
	return (mejor_s.W2 - s.W2) / mejor_s.W2;
}

cacm::salida cacm_grasp::resolver(const cacm::entrada& e, int coef_rand, int max_cant_it_sin_mejora, double epsilon)
{
  salida s, mejor_s = cacm_goloso::resolver(e, coef_rand);

  int cant_it_sin_mejora = 0;
  for (int cant_it = 0; cant_it < MAX_CANT_IT; ++cant_it)
  {
    if (max_cant_it_sin_mejora < cant_it_sin_mejora)
      break;

    s = cacm_goloso::resolver(e, coef_rand);
    cacm_busq_local::buscar_maximo_local(e, s);

    if (not s.hay_solucion)
      { ++cant_it_sin_mejora; continue; }
    if (diferencia_relativa(mejor_s, s) < epsilon)
      ++cant_it_sin_mejora;
    else
      cant_it_sin_mejora = 0;
    if (s.W2 < mejor_s.W2)
      mejor_s = s;
  }
  
  return mejor_s;
}
