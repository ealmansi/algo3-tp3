#include "cacm.h"
#include "cacm_exacto.h"
#include "cacm_goloso.h"
#include "cacm_busq_local.h"
#include "cacm_grasp.h"
using namespace cacm;

#include <iostream>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <sys/time.h>
using namespace std;

entrada generar_instancia_aleatoria(int n, int m, int max_w1, int max_w2, int K)
{
  entrada e;
  e.n = n;
  e.m = m;
  e.u = (rand() %  e.n) + 1;
  do { e.v = (rand() %  e.n) + 1; } while (e.u == e.v);
  e.K = K;
  e.adyacentes.resize(e.n + 1);

  int u, v;
  set<int> ejes; set<int>::iterator it;
  
  while (ejes.size() < e.m)
  {
    u = (rand() %  (e.n - 1)) + 1;
    do { v = (rand() %  (e.n - u)) + u + 1; } while (u == v);
    ejes.insert(u * (e.n + 1) + v);
  }

  for (it = ejes.begin(); it != ejes.end(); ++it)
  {
    u = (*it) / (e.n + 1);
    v = (*it) % (e.n + 1);
    int w1 = (rand() % max_w1) + 1;
    int w2 = (rand() % max_w2) + 1;
    e.adyacentes[u].push_back(ady(v, w1, w2));
    e.adyacentes[v].push_back(ady(u, w1, w2));
  }

  for (int i = 1; i < e.n + 1; ++i)
    e.adyacentes[i].sort(comparar_ady_por_v);

  return e;
}

int triangular(int n)
{
  if (n % 2 == 0)   return (n / 2) * (n - 1);
  else              return ((n - 1) / 2) * n;
}

typedef long long int lli;

#define CANT_MEDICIONES_POR_N 11
#define EXACTO_N_MAX 15
void medir_performance_exacto()
{
  timespec inicio, fin;
  int m, max_w1, max_w2, K;
  vector<vector<lli> > mediciones_por_n(EXACTO_N_MAX, vector<lli>(CANT_MEDICIONES_POR_N, -1));

  for (int i = 0; i < CANT_MEDICIONES_POR_N; ++i)
  {
    srand(10);
    cout << (i + 1) << "/" << CANT_MEDICIONES_POR_N << endl;
    for (int n = 5; n <= EXACTO_N_MAX; ++n)
    {
      m = triangular(n);
      max_w1 = 100;
      max_w2 = 100;
      K = 0.1 * ((n * max_w1) / 4);

      entrada e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
      cacm_exacto::resolver(e);
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);
      mediciones_por_n[n - 1][i] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);
    }
  }

  lli mediana;
  //vector<Medicion> mediciones;
  for (int n = 5; n <= EXACTO_N_MAX; ++n)
  {
    sort(mediciones_por_n[n - 1].begin(), mediciones_por_n[n - 1].end());
    mediana = mediciones_por_n[n - 1][CANT_MEDICIONES_POR_N / 2];
    cout << n << " " << mediana << endl;
    //mediciones.push_back(Medicion(n, mediana));
  }
}

int main(int argc, char const *argv[])
{
  medir_performance_exacto();
  return 0;
}