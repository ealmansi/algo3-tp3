salida cacm_exacto::resolver(const entrada& e)
{
  solucion sol, sol_opt;
  vb visitado(e.n + 1);

  sol.W1 = sol.W2 = 0;

  backtracking(e.u, e, sol, sol_opt, visitado);

  salida s;
  s.hay_solucion = e.u == e.v or not sol_opt.ejes.empty();
  s.ejes = sol_opt.ejes;
  s.u = e.u;
  s.v = e.v;
  s.W1 = sol_opt.W1;
  s.W2 = sol_opt.W2;

  return s;
}

void backtracking(int u, const entrada& e, solucion& sol, solucion& sol_opt, vb& visitado)
{
  visitado[u] = true;

  if (u == e.v)
  {
    if (sol_opt.ejes.empty() or sol.W2 < sol_opt.W2)
      sol_opt = sol;
  }
  else
  {
    lady::const_iterator i;
    for (i = e.adyacentes[u].begin(); i != e.adyacentes[u].end(); ++i)
    {
      if (not visitado[i->v] and sol.W1 + i->w1 <= e.K)
      {
        sol.ejes.push_back(eje(u, i->v, i->w1, i->w2));
        sol.W1 += i->w1; sol.W2 += i->w2;
        
        backtracking(i->v, e, sol, sol_opt, visitado);
        
        sol.W1 -= i->w1; sol.W2 -= i->w2;
        sol.ejes.pop_back();
      }
    }
  }

  visitado[u] = false;
}