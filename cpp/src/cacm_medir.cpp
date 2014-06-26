#include "cacm.h"
#include "cacm_dijkstra.h"
#include "cacm_exacto.h"
#include "cacm_goloso.h"
#include "cacm_busq_local.h"
#include "cacm_grasp.h"
using namespace cacm;

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <set>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <ctime>
#include <sys/time.h>
using namespace std;

typedef set<int> si;

int cant_aristas_K_n(int n)
{
  if (n % 2 == 0)   return (n / 2) * (n - 1);
  else              return ((n - 1) / 2) * n;
}

entrada generar_instancia_aleatoria(int n, int m, int max_w1, int max_w2, int K)
{
  entrada e;
  int u, v, w1, w2;
  si ejes; si::iterator it;
  
  e.n = n;
  e.m = m;
  e.u = (rand() %  e.n) + 1;
  do { e.v = (rand() %  e.n) + 1; } while (e.u == e.v);
  e.K = K;
  e.adyacentes.resize(e.n + 1);

  while (ejes.size() < e.m)
  {
    u = (rand() %  (e.n - 1)) + 1;
    v = (rand() %  (e.n - u)) + u + 1;
    ejes.insert(u * (e.n + 1) + v);
  }

  for (it = ejes.begin(); it != ejes.end(); ++it)
  {
    u = (*it) / (e.n + 1);
    v = (*it) % (e.n + 1);
    w1 = (rand() % max_w1) + 1;
    w2 = (rand() % max_w2) + 1;
    e.adyacentes[u].push_back(ady(v, w1, w2));
    e.adyacentes[v].push_back(ady(u, w1, w2));
  }

  for (int i = 1; i < e.n + 1; ++i)
    e.adyacentes[i].sort(comparar_ady_por_v);

  return e;
}

// typedef long double ld;
// typedef vector<ld> vld;
// #define range(c) (c).begin(), (c).end()

// void comparar_calidad()
// {
//   entrada e;
//   salida s_exacto, s_goloso, s_busq_local, s_grasp;
//   int m, max_w1, max_w2, K;
//   vld ratios_goloso, ratios_busq_local, ratios_grasp;
//   ld prom_ratios_goloso, prom_ratios_busq_local, prom_ratios_grasp;

//   int seed = time(0);
//   srand(seed);
//   cout << "seed: " << seed << endl;
//   for (int n = 5; n <= 10; ++n)
//   {
//     m = cant_aristas_K_n(n);
//     max_w1 = 10000;
//     max_w2 = 10000;
//     K = 0.5 * ((n * max_w1) / 4);

//     for (int i = 0; i < 200; ++i)
//     {
//       e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);

//       s_exacto = cacm_exacto::resolver(e);
//       s_goloso = cacm_goloso::resolver(e);
//       s_busq_local = cacm_busq_local::resolver(e);
//       s_grasp = cacm_grasp::resolver(e);

//       if (s_exacto.hay_solucion)
//       {
//         ratios_goloso.push_back(1.0l * s_goloso.W2 / s_exacto.W2);
//         ratios_busq_local.push_back(1.0l * s_busq_local.W2 / s_exacto.W2);
//         ratios_grasp.push_back(1.0l * s_grasp.W2 / s_exacto.W2);
//       }
//     }

//     prom_ratios_goloso = accumulate(range(ratios_goloso), 0.0l) / ratios_goloso.size();
//     prom_ratios_busq_local = accumulate(range(ratios_busq_local), 0.0l) / ratios_busq_local.size();
//     prom_ratios_grasp = accumulate(range(ratios_grasp), 0.0l) / ratios_grasp.size();
//     cout << n << ": " << prom_ratios_goloso << " " << prom_ratios_busq_local  << " " << prom_ratios_grasp << endl;
//   }
// }

typedef long long int lli;
typedef vector<lli> vlli;
typedef vector<vlli> vvlli;

#define CANT_MEDICIONES_POR_N 15
#define range(c) (c).begin(), (c).end()

// gráfico tiempo vs n (para distintos m si queda bien)
void medir_exacto(int n_min, int n_max)
{
  timespec inicio, fin;
  vvlli mediciones_por_n(n_max - n_min + 1, vlli(CANT_MEDICIONES_POR_N));

  for (int i = 0; i < CANT_MEDICIONES_POR_N; ++i)
  {
    srand(1234235);
    for (int n = n_min; n < n_max + 1; ++n)
    {
      cout << n << endl;
      int m = 0.8 * cant_aristas_K_n(n);
      int max_w1 = 10000;
      int max_w2 = 10000;
      int K = 1 * ((1.0l * n * max_w1) / 4.0);
      entrada e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);

      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
      cacm_exacto::resolver(e);
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);

      mediciones_por_n[n - n_min][i] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);
    }
  }

  for (int n = n_min; n < n_max + 1; ++n)
  {
    sort(range(mediciones_por_n[n - n_min]));
    cout << n << " " << mediciones_por_n[n - n_min][CANT_MEDICIONES_POR_N/2] << endl;
  }
}

int main(int argc, char const *argv[])
{
  medir_exacto(3, 13);
  return 0;
}