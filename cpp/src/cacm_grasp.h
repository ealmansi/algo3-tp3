#ifndef CACM_H_GRASP
#define CACM_H_GRASP

#include "cacm.h"

namespace cacm_grasp
{
  cacm::salida resolver(const cacm::entrada& e);
  void solucion_aleatoria(const cacm::entrada& e, cacm::salida& s, double p);
};
 
#endif /* CACM_H_GRASP */
