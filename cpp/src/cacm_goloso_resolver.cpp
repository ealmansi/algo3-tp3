#include "cacm.h"
#include "cacm_goloso.h"
using namespace cacm;
using namespace cacm_goloso;

#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<double> vd;

#define CANT_ALFAS 100
#define range(c) (c).begin(), (c).end()

/*    *    *    *    *    *    *    *    *    *    *    *    */

void dijkstra(const entrada& e, vb& visitado, vd& dist, vi& dist_w1, vi& dist_w2, vi& pred, double alfa)
{
  fill(range(visitado), false);
  fill(range(dist), INFINITY);
  fill(range(dist_w1), INFINITY);
  fill(range(dist_w2), INFINITY);
  fill(range(pred), -1);

  dist[e.u] = 0;
  dist_w1[e.u] = 0;
  dist_w2[e.u] = 0;
  pred[e.u] = -1;

  while (true)
  {
    int u, dist_u = INFINITY;
    for (int i = 1; i <= e.n; ++i)
      if (not visitado[i] && dist[i] < dist_u)
        u = i, dist_u = dist[i];

    if (dist_u == INFINITY || u == e.v)
      break;

    visitado[u] = true;

    lady::const_iterator i;
    for (i = e.adyacentes[u].begin(); i != e.adyacentes[u].end(); ++i)
    {
      double dist_u_uv = dist[u] + (1 - alfa) * i->w1 + alfa * i->w2;
      if (dist_u_uv < dist[i->v])
      {
        dist[i->v] = dist_u_uv;
        dist_w1[i->v] = dist_w1[u] + i->w1;
        dist_w2[i->v] = dist_w2[u] + i->w2;
        pred[i->v] = u;
      }
    }
  }
}

salida cacm_goloso::resolver(const entrada& e)
{
  vd alfas(CANT_ALFAS);
  for (int i = 0; i < CANT_ALFAS; ++i)
    alfas[CANT_ALFAS - (i + 1)] = ((double) i) / CANT_ALFAS;

  vb visitado(e.n + 1);
  vd dist(e.n + 1);
  vi dist_w1(e.n + 1);
  vi dist_w2(e.n + 1);
  vi pred(e.n + 1);

  vd::const_iterator alfa;
  for (alfa = alfas.begin(); alfa != alfas.end(); ++alfa)
  {
    dijkstra(e, visitado, dist, dist_w1, dist_w2, pred, *alfa);
    
    if (dist_w1[e.v] <= e.K)
    {
      salida s;
      s.hay_solucion = true;
      
      for (int v = e.v; pred[v] != -1; v = pred[v])
      {
        int w1 = dist_w1[v] - dist_w1[pred[v]],
        w2 = dist_w2[v] - dist_w2[pred[v]];
        s.ejes.push_front(eje(pred[v], v, w1, w2));
      }

      s.u = e.u;
      s.v = e.v;
      s.W1 = dist_w1[e.v];
      s.W2 = dist_w2[e.v];

      return s;
    }
  }

  salida s;
  s.hay_solucion = false;

  return s;
}

