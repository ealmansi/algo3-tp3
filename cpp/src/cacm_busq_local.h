#ifndef CACM_H_BUSQ_LOCAL
#define CACM_H_BUSQ_LOCAL

#include "cacm.h"

namespace cacm_busq_local
{
  cacm::salida resolver(const cacm::entrada& e);
  void buscar_maximo_local(const cacm::entrada& e, cacm::salida& s);
};
 
#endif /* CACM_H_BUSQ_LOCAL */
