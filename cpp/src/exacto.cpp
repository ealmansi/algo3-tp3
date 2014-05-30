#include "cacm.h"
using namespace cacm;

#include <iostream>
#include <list>
#include <vector>
using namespace std;

typedef list<int> li;
typedef vector<bool> vb;

struct solucion
{
  li camino;
  int W1, W2;
};

/*    *    *    *    *    *    *    *    *    *    *    *    */

void backtracking(const entrada& e, solucion& sol, solucion& sol_opt, vb& visitado)
{
  int u = sol.camino.back();

  if (u == e.v)
  {
    if (sol_opt.camino.empty() or sol.W2 < sol_opt.W2)
      sol_opt = sol;
  }
  else
  {
    lady::const_iterator i;
    for (i = e.adyacentes[u].begin(); i != e.adyacentes[u].end(); ++i)
    {
      if (not visitado[i->v] and sol.W1 + i->w1 <= e.K)
      {
        sol.camino.push_back(i->v);
        sol.W1 += i->w1; sol.W2 += i->w2;
        visitado[i->v] = true;
        
        backtracking(e, sol, sol_opt, visitado);

        visitado[i->v] = false;
        sol.W1 -= i->w1; sol.W2 -= i->w2;
        sol.camino.pop_back();
      }
    }
  }
}

salida resolver(const entrada& e)
{
  solucion sol, sol_opt;
  vb visitado(e.n + 1);

  sol.camino.push_back(e.u);
  sol.W1 = sol.W2 = 0;
  visitado[e.u] = true;

  backtracking(e, sol, sol_opt, visitado);

  salida s;
  s.hay_solucion = not sol_opt.camino.empty();
  s.camino = sol_opt.camino;
  s.W1 = sol_opt.W1;
  s.W2 = sol_opt.W2;

  return s;
}

int main(int argc, char const *argv[])
{
  entrada e;
  while(leer_instancia(e))
  {
    salida s = resolver(e);
    escribir_salida(s);
  }

  return 0;
}