#ifndef CACM_H_GOLOSO
#define CACM_H_GOLOSO

#include "cacm.h"
#include <vector>
#define NULL 0

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<double> vd;

namespace cacm_goloso
{
  cacm::salida resolver(const cacm::entrada& e, int cant_it, double* p = NULL);
  void dijkstra(const cacm::entrada& e, vb& visitado, vd& dist, vi& dist_w1, vi& dist_w2, vi& pred, double alfa);
};
 
#endif /* CACM_H_GOLOSO */
