#include "cacm.h"
#include "cacm_goloso.h"
#include "cacm_busq_local.h"
using namespace cacm;
using namespace cacm_busq_local;

#include <iostream>
#include <algorithm>
using namespace std;

#define range(c) (c).begin(), (c).end()

struct solucion
{
  leje ejes;
  int W1, W2;
};

struct vecino
{
  typedef enum
  {
    V_TIPO_1, // vecinos formados al cambiar (u,v) por (u,x)(x,v)
    V_TIPO_2, // vecinos formados al cambiar (u,v)(v,z) por (u,z)
    V_TIPO_3, // vecinos formados al cambiar (u,v)(v,z) por (u,x)(x,z)
  V_INVALIDO} v_tipo;

  vecino() : tipo(V_INVALIDO) {}

  v_tipo tipo;
  leje::iterator pos;
  leje ejes_nuevos;
  int W1, W2;
};

/*    *    *    *    *    *    *    *    *    *    *    *    */

// vecinos formados al cambiar (u,v) por (u,x)(x,v)
void buscar_vecinos_tipo_1(solucion& sol, vecino& mejor_vecino, const entrada& e)
{
  // para cada eje (u,v) en la solucion
  leje::iterator it_uv;
  for (it_uv = sol.ejes.begin(); it_uv != sol.ejes.end(); ++it_uv)
  {
    eje& uv = *it_uv;

    // para cada vertice adyacente a ambos extremos de (u,v)
    lady::const_iterator it_ady_u = e.adyacentes[uv.u].begin(), it_ady_v = e.adyacentes[uv.v].begin();
    while (it_ady_u != e.adyacentes[uv.u].end() and it_ady_v != e.adyacentes[uv.v].end())
    {
      const ady& ady_u = *it_ady_u, ady_v = *it_ady_v;

      if (ady_u.v < ady_v.v) ++it_ady_u;
      else if (ady_v.v < ady_u.v) ++it_ady_v;
      else
      {
        // actualizo mejor_vecino si esta solucion vecina es valida y es mejor
        int W1_prima = sol.W1 - uv.w1 + ady_u.w1 + ady_v.w1,
        W2_prima = sol.W2 - uv.w2 + ady_u.w2 + ady_v.w2;
        if (W1_prima <= e.K and (mejor_vecino.tipo == vecino::V_INVALIDO or W2_prima < mejor_vecino.W2))
        {
          mejor_vecino.tipo = vecino::V_TIPO_1;
          mejor_vecino.pos = it_uv;
          mejor_vecino.ejes_nuevos.clear();
          mejor_vecino.ejes_nuevos.push_back(eje(uv.u, ady_u.v, ady_u.w1, ady_u.w2));
          mejor_vecino.ejes_nuevos.push_back(eje(ady_v.v, uv.v, ady_v.w1, ady_v.w2));
          mejor_vecino.W1 = W1_prima;
          mejor_vecino.W2 = W2_prima;
        }

        ++it_ady_u, ++it_ady_v;
      }
    }
  }
}

salida cacm_busq_local::resolver(const entrada& e)
{
  salida s_golsoso = cacm_goloso::resolver(e);
  if (not s_golsoso.hay_solucion)
    return s_golsoso;

  solucion sol = {.ejes = s_golsoso.ejes, .W1 = s_golsoso.W1, .W2 = s_golsoso.W2};

  bool seguir_buscando = true;
  while (seguir_buscando)
  {
    vecino mejor_vecino;
    buscar_vecinos_tipo_1(sol, mejor_vecino, e);

    if (mejor_vecino.tipo == vecino::V_INVALIDO or not mejor_vecino.W2 < sol.W2)
      seguir_buscando = false;
    else
    {
      switch (mejor_vecino.tipo)
      {
      case vecino::V_TIPO_1:
        mejor_vecino.pos = sol.ejes.erase(mejor_vecino.pos);
        sol.ejes.insert(mejor_vecino.pos, range(mejor_vecino.ejes_nuevos));
        sol.W1 = mejor_vecino.W1;
        sol.W2 = mejor_vecino.W2;
        break;
      }
    }
  }

  return s_golsoso;
}
