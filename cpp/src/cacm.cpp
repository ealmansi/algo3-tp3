#include "cacm.h"
using namespace cacm;

#include <iostream>
#include <list>
using namespace std;

typedef list<int> li;

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

void cacm::escribir_salida(const salida& s)
{
  if (s.hay_solucion)
  {
    cout << s.W1 << " " << s.W2 << " " << s.camino.size() << " ";
    li::const_iterator i;
    for (i = s.camino.begin(); i != s.camino.end(); ++i)
    {
      cout << *i;
      if(i != --s.camino.end())
        cout << " ";
      else
        cout << endl;
    }
  }
  else
  {
    cout << "no" << endl;
  }
}
