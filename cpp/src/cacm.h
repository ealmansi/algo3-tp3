#ifndef CACM_H
#define CACM_H

#include <list>
#include <vector>

namespace cacm
{
  struct ady;
  struct eje;
  typedef std::list<ady> lady;
  typedef std::list<eje> leje;
  typedef std::vector<lady> vlady;

  struct ady
  {
    ady(int v, int w1, int w2) : v(v), w1(w1), w2(w2) {}
    int v, w1, w2;
  };
  bool comparar_ady_por_v(const ady& a, const ady& b);

  struct eje
  {
    eje(int u, int v, int w1, int w2) : u(u), v(v), w1(w1), w2(w2) {}
    int u, v, w1, w2;
  };

  struct entrada
  {
    int n, m, u, v, K;
    vlady adyacentes;
  };

  struct salida
  {
    bool hay_solucion;
    leje ejes;
    int u, v, W1, W2;
  };

  bool leer_instancia(entrada& e);
  bool leer_instancia_listas_ordenadas(entrada& e);
  void escribir_salida(const salida& s);
};
 
#endif /* CACM_H */
