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

bool comparar_ady_por_v(const ady& a, const ady& b)
{
  return a.v < b.v;
}

bool cacm::leer_instancia_listas_ordenadas(entrada& e)
{
  if (not leer_instancia(e))
    return false;

  for (int i = 0; i < e.n + 1; ++i)
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

entrada cacm::grafo_rompe(int i){
	entrada e;
	e.n = 5;
	e.m = 6;
	e.u = 1;
	e.v = 5;
	e.K = 2*i;
	e.adyacentes.resize(e.n+1);
	e.adyacentes[1].push_back(ady(2,i+1,1));
	e.adyacentes[2].push_back(ady(1,i+1,1));
	e.adyacentes[1].push_back(ady(3,i,i));
	e.adyacentes[3].push_back(ady(1,i,i));
	e.adyacentes[1].push_back(ady(4,1,i+1));
	e.adyacentes[4].push_back(ady(1,1,i+1));
	
	e.adyacentes[5].push_back(ady(2,i+1,1));
	e.adyacentes[2].push_back(ady(5,i+1,1));
	e.adyacentes[5].push_back(ady(3,i,i));
	e.adyacentes[3].push_back(ady(5,i,i));
	e.adyacentes[5].push_back(ady(4,1,i+1));
	e.adyacentes[4].push_back(ady(5,1,i+1));
	
	return e;
}

