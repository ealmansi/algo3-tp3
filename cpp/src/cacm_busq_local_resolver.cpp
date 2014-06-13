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
    int u = uv.u, v = uv.v;

    // para cada vertice adyacente a ambos extremos de (u,v)
    lady::const_iterator it_ady_u = e.adyacentes[u].begin(), it_ady_v = e.adyacentes[v].begin();
    while (it_ady_u != e.adyacentes[u].end() and it_ady_v != e.adyacentes[v].end())
    {
      const ady& ady_u = *it_ady_u, ady_v = *it_ady_v;

      if (ady_u.v < ady_v.v) ++it_ady_u;
      else if (ady_v.v < ady_u.v) ++it_ady_v;
      else
      {
        int x = ady_u.v;

        // actualizo mejor_vecino si esta solucion vecina es valida y es mejor
        int W1_prima = sol.W1 - uv.w1 + ady_u.w1 + ady_v.w1,
        W2_prima = sol.W2 - uv.w2 + ady_u.w2 + ady_v.w2;
        if (W1_prima <= e.K and (mejor_vecino.tipo == vecino::V_INVALIDO or W2_prima < mejor_vecino.W2))
        {
          mejor_vecino.tipo = vecino::V_TIPO_1;
          mejor_vecino.pos = it_uv;
          mejor_vecino.ejes_nuevos.clear();
          mejor_vecino.ejes_nuevos.push_back(eje(u, x, ady_u.w1, ady_u.w2));
          mejor_vecino.ejes_nuevos.push_back(eje(x, v, ady_v.w1, ady_v.w2));
          mejor_vecino.W1 = W1_prima;
          mejor_vecino.W2 = W2_prima;
        }

        ++it_ady_u, ++it_ady_v;
      }
    }
  }
}

// vecinos formados al cambiar (u,v)(v,z) por (u,z)
void buscar_vecinos_tipo_2(solucion& sol, vecino& mejor_vecino, const entrada& e)
{
  // para cada par de ejes (u,v)(v,z) en la solucion
  leje::iterator it_uv = sol.ejes.begin(), it_vz = sol.ejes.begin(); ++it_vz;
  for (; it_vz != sol.ejes.end(); ++it_uv, ++it_vz)
  {
    eje& uv = *it_uv, vz = *it_vz;
    int u = uv.u, v = uv.v, z = vz.v;

    // busco a z entre los adyacentes de u
    lady::const_iterator it_ady_u;
    for (it_ady_u = e.adyacentes[u].begin(); it_ady_u != e.adyacentes[u].end(); ++it_ady_u)
    {
      const ady& ady_u = *it_ady_u;

      if (ady_u.v != z) continue;

      // actualizo mejor_vecino si esta solucion vecina es valida y es mejor
      int W1_prima = sol.W1 - uv.w1 - vz.w1 + ady_u.w1,
      W2_prima = sol.W2 - uv.w2 - vz.w2 + ady_u.w2;
      if (W1_prima <= e.K and (mejor_vecino.tipo == vecino::V_INVALIDO or W2_prima < mejor_vecino.W2))
      {
        mejor_vecino.tipo = vecino::V_TIPO_2;
        mejor_vecino.pos = it_uv;
        mejor_vecino.ejes_nuevos.clear();
        mejor_vecino.ejes_nuevos.push_back(eje(u, z, ady_u.w1, ady_u.w2));
        mejor_vecino.W1 = W1_prima;
        mejor_vecino.W2 = W2_prima;
      }

      break;
    }
  }
}

// vecinos formados al cambiar (u,v)(v,z) por (u,x)(x,z)
void buscar_vecinos_tipo_3(solucion& sol, vecino& mejor_vecino, const entrada& e)
{
  // para cada par de ejes (u,v)(v,z) en la solucion
  leje::iterator it_uv = sol.ejes.begin(), it_vz = sol.ejes.begin(); ++it_vz;
  for (; it_vz != sol.ejes.end(); ++it_uv, ++it_vz)
  {
    eje& uv = *it_uv, vz = *it_vz;
    int u = uv.u, v = uv.v, z = vz.v;

    // para cada vertice adyacente a `u` y a `z`
    lady::const_iterator it_ady_u = e.adyacentes[u].begin(), it_ady_z = e.adyacentes[z].begin();
    while (it_ady_u != e.adyacentes[u].end() and it_ady_z != e.adyacentes[z].end())
    {
      const ady& ady_u = *it_ady_u, ady_z = *it_ady_z;

      if (ady_u.v < ady_z.v) ++it_ady_u;
      else if (ady_z.v < ady_u.v) ++it_ady_z;
      else
      {
        int x = ady_u.v;

        // actualizo mejor_vecino si esta solucion vecina es valida y es mejor
        int W1_prima = sol.W1 - uv.w1 - vz.w1 + ady_u.w1 + ady_z.w1,
        W2_prima = sol.W2 - uv.w2 - vz.w2 + ady_u.w2 + ady_z.w2;
        if (W1_prima <= e.K and (mejor_vecino.tipo == vecino::V_INVALIDO or W2_prima < mejor_vecino.W2))
        {
          mejor_vecino.tipo = vecino::V_TIPO_3;
          mejor_vecino.pos = it_uv;
          mejor_vecino.ejes_nuevos.clear();
          mejor_vecino.ejes_nuevos.push_back(eje(u, x, ady_u.w1, ady_u.w2));
          mejor_vecino.ejes_nuevos.push_back(eje(x, z, ady_z.w1, ady_z.w2));
          mejor_vecino.W1 = W1_prima;
          mejor_vecino.W2 = W2_prima;
        }

        ++it_ady_u, ++it_ady_z;
      }
    }
  }
}

salida cacm_busq_local::resolver(const entrada& e)
{
  salida s = cacm_goloso::resolver(e,20,NULL);
  busqueda_local(e,s);
  return s;
}

void cacm_busq_local::busqueda_local(const entrada& e, salida& s)
{
  if (not s.hay_solucion)
    return ;
	
	solucion sol;
	sol.ejes = s.ejes;
	sol.W1 = s.W1;
	sol.W2 = s.W2;

  bool seguir_buscando = true;
  while (seguir_buscando)
  {
    vecino mejor_vecino;
    buscar_vecinos_tipo_1(sol, mejor_vecino, e);
    buscar_vecinos_tipo_2(sol, mejor_vecino, e);
    buscar_vecinos_tipo_3(sol, mejor_vecino, e);

    if (mejor_vecino.tipo == vecino::V_INVALIDO or not mejor_vecino.W2 < sol.W2)
    {
      seguir_buscando = false;
    }
    else
    {
      switch (mejor_vecino.tipo)
      {
      case vecino::V_TIPO_1:
        mejor_vecino.pos = sol.ejes.erase(mejor_vecino.pos);
        sol.ejes.insert(mejor_vecino.pos, range(mejor_vecino.ejes_nuevos));
        break;
      case vecino::V_TIPO_2:
        mejor_vecino.pos = sol.ejes.erase(mejor_vecino.pos);
        mejor_vecino.pos = sol.ejes.erase(mejor_vecino.pos);
        sol.ejes.insert(mejor_vecino.pos, range(mejor_vecino.ejes_nuevos));
        break;
      case vecino::V_TIPO_3:
        mejor_vecino.pos = sol.ejes.erase(mejor_vecino.pos);
        mejor_vecino.pos = sol.ejes.erase(mejor_vecino.pos);
        sol.ejes.insert(mejor_vecino.pos, range(mejor_vecino.ejes_nuevos));
        break;
      }
      sol.W1 = mejor_vecino.W1;
      sol.W2 = mejor_vecino.W2;
    }
  }

  s.hay_solucion = true;
  s.ejes = sol.ejes;
  s.u = e.u;
  s.v = e.v;
  s.W1 = sol.W1;
  s.W2 = sol.W2;
}
