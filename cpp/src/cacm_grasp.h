#ifndef CACM_H_GRASP
#define CACM_H_GRASP

#include "cacm.h"

namespace cacm_grasp
{
  cacm::salida resolver(const cacm::entrada& e, int coef_rand = 0.5, int max_cant_it_sin_mejora = 20, double epsilon = 0.01);
};
 
#endif /* CACM_H_GRASP */
