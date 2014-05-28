#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct ady;
typedef vector<int> vi;
typedef list<int> li;
typedef vector<bool> vb;
typedef list<ady> lady;
typedef vector<lady> vlady;

struct ady
{
  ady(int v, int w1, int w2) : v(v), w1(w1), w2(w2) {}
  int v, w1, w2;
};

struct solucion
{
  li camino;
  int W1, W2;
};

struct Entrada
{
  int n, m, u, v, K;
  vlady adyacentes;
};

struct Salida
{
  Salida(li c, int W1, int W2) : hay_solucion(not c.empty()),
    camino(c.begin(), c.end()), W1(W1), W2(W2) {}
  
  bool hay_solucion;
  vi camino;
  int W1, W2;
};

bool leer_instancia(Entrada& e)
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

void backtracking(const Entrada& e, solucion& sol, solucion& sol_opt, vb& visitado)
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

Salida resolver(const Entrada& e)
{
  solucion sol, sol_opt;
  vb visitado(e.n + 1);

  sol.camino.push_back(e.u);
  sol.W1 = sol.W2 = 0;
  visitado[e.u] = true;

  backtracking(e, sol, sol_opt, visitado);

  return Salida(sol_opt.camino, sol_opt.W1, sol_opt.W2);
}

void escribir_salida(const Salida& s)
{
  if (s.hay_solucion)
  {
    cout << s.W1 << " " << s.W2 << " " << s.camino.size() << " ";
    for (int i = 0; i < s.camino.size(); ++i)
    {
      cout << s.camino[i];
      if(i + 1 < s.camino.size())
        cout << " ";
    }
    cout << endl;
  }
  else
  {
    cout << "no" << endl;
  }
}

int main(int argc, char const *argv[])
{
  Entrada e;
  while(leer_instancia(e))
  {
    Salida s = resolver(e);
    escribir_salida(s);
  }

  return 0;
}