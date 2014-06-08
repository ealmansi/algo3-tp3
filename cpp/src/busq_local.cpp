#include "cacm.h"
#include "cacm_goloso.h"
using namespace cacm;

#include <iostream>
#include <list>
#include <vector>
using namespace std;

typedef list<int> li;
typedef vector<bool> vb;

struct operacion
{
  typedef enum {OP_AGREGAR, OP_BORRAR, OP_CAMBIAR, NINGUNA} tipo_op;
  operacion(tipo_op tipo = NINGUNA) : tipo(tipo) {}
  tipo_op tipo;
};

struct op_agregar : operacion
{
  op_agregar(leje::iterator& pos, eje u_x, eje x_v)
    : operacion(OP_AGREGAR), pos(pos), u_x(u_x), x_v(x_v) {}
  leje::iterator& pos;
  eje u_x, x_v;
};

struct op_borrar : operacion
{
  op_borrar(int pos) : operacion(OP_BORRAR), pos(pos) {}
  int pos;
};

struct op_cambiar : operacion
{
  op_cambiar(int pos, int v) : operacion(OP_CAMBIAR), pos(pos), v(v) {}
  int pos, v;
};

/*    *    *    *    *    *    *    *    *    *    *    *    */

salida resolver(const entrada& e)
{
  salida s_golsoso = cacm_goloso::resolver(e);
  if (not s_golsoso.hay_solucion)
    return s_golsoso;

  leje& ejes = s_golsoso.ejes;
  int W1 = s_golsoso.W1, W2 = s_golsoso.W2;

  bool seguir_buscando = true;
  while (seguir_buscando)
  {
    seguir_buscando = false;
  }

  return s_golsoso;
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
