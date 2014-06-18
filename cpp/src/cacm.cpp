#include "cacm.h"
using namespace cacm;

#include <iostream>
#include <list>
using namespace std;

/*    *    *    *    *    *    *    *    *    *    *    *    */

bool cacm::leer_instancia(entrada& e)
{
  cin >> e.n;
  if (e.n == 0) return false;
  cin >> e.m >> e.u >> e.v >> e.K;

  e.adyacentes.clear();
  e.adyacentes.resize(e.n + 1);

  int v1, v2, w1, w2;
  for (int i = 0; i < e.m; ++i)
  {
    cin >> v1 >> v2 >> w1 >> w2;
    e.adyacentes[v1].push_back(ady(v2, w1, w2));
    e.adyacentes[v2].push_back(ady(v1, w1, w2));
  }

  return true;
}

bool cacm::comparar_ady_por_v(const ady& a, const ady& b)
{
  return a.v < b.v;
}

bool cacm::leer_instancia_listas_ordenadas(entrada& e)
{
  if (not leer_instancia(e))
    return false;

  for (int i = 1; i < e.n + 1; ++i)
    e.adyacentes[i].sort(comparar_ady_por_v);

  return true;
}

void cacm::escribir_salida(const salida& s)
{
  if (s.hay_solucion)
  {
    cout << s.W1 << " " << s.W2 << " " << (s.ejes.size() + 1) << " ";
    
    cout << s.u;
    if(not s.ejes.empty()) cout << " ";
    else cout << endl;

    leje::const_iterator i;
    for (i = s.ejes.begin(); i != s.ejes.end(); ++i)
    {
      cout << i->v;
      if(i != --s.ejes.end()) cout << " ";
      else cout << endl;
    }
  }
  else
  {
    cout << "no" << endl;
  }
}
