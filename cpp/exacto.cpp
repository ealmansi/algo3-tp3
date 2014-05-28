#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct ady
{
  ady(int v, int w1, int w2) : v(v), w1(w1), w2(w2) {}
  int v, w1, w2;
};
struct nodo_bt
{
  nodo_bt(int v, int W1, int W2) : v(v), W1(W1), W2(W2) {}
  int v, W1, W2;
};

typedef vector<int> vi;
typedef vector<bool> vb;
typedef list<ady> lady;
typedef vector<lady> vlady;
typedef list<nodo_bt> lnodo_bt;

struct Entrada
{
  int n, m, u, v, K;
  vlady adyacentes;
};

struct Salida
{
  bool hay_solucion;
  int W1, W2;
  vi camino;
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

void backtracking(const Entrada& e, lnodo_bt& sol, lnodo_bt& sol_opt, vb& visitado)
{
  nodo_bt nodo = sol.back();

  if (nodo.v == e.v)
  {
    if (sol_opt.empty() or nodo.W2 < sol_opt.back().W2)
      sol_opt = sol;
  }
  else
  {
    lady::const_iterator i;
    for (i = e.adyacentes[nodo.v].begin(); i != e.adyacentes[nodo.v].end(); ++i)
    {
      if (not visitado[i->v] and nodo.W1 + i->w1 <= e.K)
      {
        sol.push_back(nodo_bt(i->v, nodo.W1 + i->w1, nodo.W2 + i->w2));
        visitado[i->v] = true;
        
        backtracking(e, sol, sol_opt, visitado);

        visitado[i->v] = false;
        sol.pop_back();
      }
    }
  }
}

Salida resolver(const Entrada& e)
{
  lnodo_bt sol, sol_opt;
  vb visitado(e.n + 1);

  sol.push_back(nodo_bt(e.u, 0, 0));
  visitado[e.u] = true;

  backtracking(e, sol, sol_opt, visitado);

  Salida s;
  s.hay_solucion = not sol_opt.empty();
  if (s.hay_solucion)
  {
    s.W1 = sol_opt.back().W1;
    s.W2 = sol_opt.back().W2;
    lnodo_bt::const_iterator i;
    for (i = sol_opt.begin(); i != sol_opt.end(); ++i)
      s.camino.push_back(i->v);
  }

  return s;
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