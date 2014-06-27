salida cacm_goloso::resolver(const entrada& e, double coef_rand)
{
  salida s;

  double inicio = 0.0, fin = 1.0, medio;
  for (int i = 0; i < CANT_IT; ++i)
  {
    medio = (inicio + fin) / 2;
    s = cacm_dijkstra::resolver(e, medio, coef_rand);
    if (s.hay_solucion)
      inicio = medio;
    else
      fin = medio;
  }

  if (not s.hay_solucion)
      s = cacm_dijkstra::resolver(e, inicio, coef_rand);

  return s;
}