#ifndef CACM_H
#define CACM_H

#include <list>
#include <vector>

namespace cacm
{
  struct ady;
  typedef std::list<int> li;
  typedef std::list<ady> lady;
  typedef std::vector<lady> vlady;

  struct ady
  {
    ady(int v, int w1, int w2) : v(v), w1(w1), w2(w2) {}
    int v, w1, w2;
  };

  struct entrada
  {
    int n, m, u, v, K;
    vlady adyacentes;
  };

  struct salida
  {
    bool hay_solucion;
    li camino;
    int W1, W2;
  };

  bool leer_instancia(entrada& e);
  void escribir_salida(const salida& s);
};
 
#endif /* CACM_H */