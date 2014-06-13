#ifndef CACM_H_GOLOSO
#define CACM_H_GOLOSO

#include "cacm.h"
#define NULL 0

namespace cacm_goloso
{
  cacm::salida resolver(const cacm::entrada& e, int cant_it, double* p = NULL);
  void dijkstra(const cacm::entrada& e, vector<bool>& visitado, vector<double>& dist, vector<int>& dist_w1, vector<int>& dist_w2, vector<int>& pred, double alfa);
};
 
#endif /* CACM_H_GOLOSO */
