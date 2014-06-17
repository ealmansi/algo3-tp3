#include "cacm.h"
#include "cacm_goloso.h"
#include "cacm_busq_local.h"
#include "cacm_grasp.h"
using namespace cacm;
using namespace cacm_grasp;

#include <cmath>
using namespace std;

#define COEF_RAND 0.1
#define MAX_CANT_IT 1000
#define MAX_CANT_IT_SIN_MEJORA 20
#define EPSILON 0.01


double error_relativo(salida& mejor_s, salida& s)
{
	return abs(mejor_s.W2 - s.W2) / mejor_s.W2;
}

salida cacm_grasp::resolver(const entrada& e)
{
  salida s, mejor_s = cacm_goloso::resolver(e, COEF_RAND);

  int cant_it_sin_mejora = 0;
  for (int cant_it = 0; cant_it < MAX_CANT_IT; ++cant_it)
  {
    s = cacm_goloso::resolver(e, COEF_RAND);
  	cacm_busq_local::buscar_maximo_local(e, s);

    if (not s.hay_solucion or error_relativo(mejor_s, s) < EPSILON)
      ++cant_it_sin_mejora;
    else if (s.W2 < mejor_s.W2)
      mejor_s = s;

    if (MAX_CANT_IT_SIN_MEJORA < cant_it_sin_mejora)
      break;
  }
  
  return mejor_s;
}
