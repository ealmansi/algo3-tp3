#include "cacm.h"
#include "cacm_dijkstra.h"
#include "cacm_exacto.h"
#include "cacm_goloso.h"
#include "cacm_busq_local.h"
#include "cacm_grasp.h"
using namespace cacm;

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <set>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <ctime>
#include <sys/time.h>
using namespace std;

typedef set<int> si;

int cant_aristas_K_n(int n)
{
  if (n % 2 == 0)   return (n / 2) * (n - 1);
  else              return ((n - 1) / 2) * n;
}

entrada generar_instancia_aleatoria(int n, int m, int max_w1, int max_w2, int K)
{
  entrada e;
  int u, v, w1, w2;
  si ejes; si::iterator it;
  
  e.n = n;
  e.m = m;
  e.u = (rand() %  e.n) + 1;
  do { e.v = (rand() %  e.n) + 1; } while (e.u == e.v);
  e.K = K;
  e.adyacentes.resize(e.n + 1);

  while (ejes.size() < e.m)
  {
    u = (rand() %  (e.n - 1)) + 1;
    v = (rand() %  (e.n - u)) + u + 1;
    ejes.insert(u * (e.n + 1) + v);
  }

  for (it = ejes.begin(); it != ejes.end(); ++it)
  {
    u = (*it) / (e.n + 1);
    v = (*it) % (e.n + 1);
    w1 = (rand() % max_w1) + 1;
    w2 = (rand() % max_w2) + 1;
    e.adyacentes[u].push_back(ady(v, w1, w2));
    e.adyacentes[v].push_back(ady(u, w1, w2));
  }

  for (int i = 1; i < e.n + 1; ++i)
    e.adyacentes[i].sort(comparar_ady_por_v);

  return e;
}

entrada grafo_rompe_goloso(int n, int i	) //n mayor que 5
{
  entrada e;
  e.n = n;
  e.m = n+1;
  e.u = 1;
  e.v = n - ((n-2) % 3);
  int k = ((n-2)/ 3);
  int proporcion = 2*i-1;
  e.K = proporcion*(k+1) ;
  //i = i / k;
  //if(i == 0){i++;}
  //if((i % k) != 0){i++;}
  int q = 3;//k==1 ? ((k+i-1)/ k) +1 : ((k+i-1)/ (k-1)) +1;
  
  //cout << " K: " << k << " q: " << q << endl;
  e.adyacentes.resize(e.n+1);
  int j = e.u+1;
  // Primer Camino, mas que la cota
  
  e.adyacentes[e.u].push_back(ady(2,proporcion+1,1));
  e.adyacentes[2].push_back(ady(e.u,proporcion+1,1));
  
  for(int p = 0; p < k-1; p++)
  {
  	e.adyacentes[j].push_back(ady(j+1,proporcion+1,1));
  	e.adyacentes[j+1].push_back(ady(j,proporcion+1,1));
  	j++;
  }
  
  e.adyacentes[j].push_back(ady(e.v,proporcion+1,1));
  e.adyacentes[e.v].push_back(ady(j,proporcion+1,1));
  
  j++;
  
  //segundo camino, optimo
  e.adyacentes[e.u].push_back(ady(j,proporcion,q));
  e.adyacentes[j].push_back(ady(e.u,proporcion,q));
  
  for(int p = 0; p < k-1; p++)
  {
  	e.adyacentes[j].push_back(ady(j+1,proporcion,q));
  	e.adyacentes[j+1].push_back(ady(j,proporcion,q));
  	j++;
  }
  
  e.adyacentes[j].push_back(ady(e.v,proporcion,q));
  e.adyacentes[e.v].push_back(ady(j,proporcion,q));
  
  j++;
  //tercer camino, sub-optimo valido
  e.adyacentes[e.u].push_back(ady(j,1,q*i));
  e.adyacentes[j].push_back(ady(e.u,1,q*i));
  for(int p = 0; p < k-1 ; p++)
  {
  	e.adyacentes[j].push_back(ady(j+1,1,q*i));
  	e.adyacentes[j+1].push_back(ady(j,1,q*i));
  	j++;
  }
  
  e.adyacentes[j].push_back(ady(e.v,1,q*i));
  e.adyacentes[e.v].push_back(ady(j,1,q*i));
  
  return e;
}

entrada grafo_rompe_goloso2(int n, int i ) //n mayor que 11 y cada 6
{
  entrada e;
  e.n = n;
  e.m = n+1;
  e.u = 1;
  e.v = n - ((n-2) % 3);
  int k = ((n-2)/ 3);
  int proporcion = 2*i-1;
  e.K = proporcion*(k+1) ;
  //i = i / k;
  //if(i == 0){i++;}
  //if((i % k) != 0){i++;}
  int q = 3;//k==1 ? ((k+i-1)/ k) +1 : ((k+i-1)/ (k-1)) +1;
  
  //cout << " K: " << k << " q: " << q << endl;
  e.adyacentes.resize(e.n+1);
  int j = e.u+1;
  // Primer Camino, mas que la cota
  
  e.adyacentes[e.u].push_back(ady(2,proporcion+1,1));
  e.adyacentes[2].push_back(ady(e.u,proporcion+1,1));
  
  for(int p = 0; p < k-1; p++)
  {
    e.adyacentes[j].push_back(ady(j+1,proporcion+1,1));
    e.adyacentes[j+1].push_back(ady(j,proporcion+1,1));
    j++;
  }
  
  e.adyacentes[j].push_back(ady(e.v,proporcion+1,1));
  e.adyacentes[e.v].push_back(ady(j,proporcion+1,1));
  
  j++;
  
  //segundo camino, optimo
  e.adyacentes[e.u].push_back(ady(j,proporcion,q));
  e.adyacentes[j].push_back(ady(e.u,proporcion,q));
  
  for(int p = 0; p < k-1; p++)
  {
    e.adyacentes[j].push_back(ady(j+1,proporcion,q));
    e.adyacentes[j+1].push_back(ady(j,proporcion,q));
    j++;
  }
  
  e.adyacentes[j].push_back(ady(e.v,proporcion,q));
  e.adyacentes[e.v].push_back(ady(j,proporcion,q));
  
  j++;
  //tercer camino, sub-optimo valido
  int g = j;
  e.adyacentes[e.u].push_back(ady(j,1,q*i));
  e.adyacentes[j].push_back(ady(e.u,1,q*i));
  for(int p = 0; p < k-1 ; p++)
  {
    e.adyacentes[j].push_back(ady(j+1,1,q*i));
    e.adyacentes[j+1].push_back(ady(j,1,q*i));
    j++;
  }
  
  e.adyacentes[j].push_back(ady(e.v,1,q*i));
  e.adyacentes[e.v].push_back(ady(j,1,q*i));
  
  //cout << g << " adyacente con: " << g-k+1 << endl;
  e.adyacentes[g].push_back(ady(g-k+1,proporcion,q*i-1));
  e.adyacentes[g-k+1].push_back(ady(g,proporcion,q*i-1));

  g+=2;
  for(int p = 0; p < k-4 ; p+=2)
  {
    //cout << g << " adyacente con: " << g-k+1 << " y " << g-k-1 << endl;
    e.adyacentes[g].push_back(ady(g-k+1,proporcion,q*i-1));
    e.adyacentes[g-k+1].push_back(ady(g,proporcion,q*i-1));

    e.adyacentes[g].push_back(ady(g-k-1,proporcion,q*i-1));
    e.adyacentes[g-k-1].push_back(ady(g,proporcion,q*i-1));

    g+=2;
  }
  //cout << g << " adyacente con: " << g-k-1 ;
  e.adyacentes[g].push_back(ady(g-k-1,proporcion,q*i-1));
  e.adyacentes[g-k-1].push_back(ady(g,proporcion,q*i-1));
  if(k % 2 == 0)
  {
    //cout << " y " << g-k+1 ;
    e.adyacentes[g].push_back(ady(g-k+1,proporcion,q*i-1));
    e.adyacentes[g-k+1].push_back(ady(g,proporcion,q*i-1));
  }
  //cout << endl;
  for (int i = 1; i < e.n + 1; ++i)
    e.adyacentes[i].sort(comparar_ady_por_v);

  return e;
}

typedef long long int lli;
typedef vector<lli> vlli;
typedef vector<vlli> vvlli;

#define CANT_MEDICIONES_POR_N_EXACTO 15
#define range(c) (c).begin(), (c).end()

// gráfico tiempo vs n (para distintos m si queda bien)
void medir_exacto(int n_min, int n_max)
{
  cout << "Medicion exacto" << endl;
  timespec inicio, fin;
  vvlli mediciones_por_n(n_max - n_min + 1, vlli(CANT_MEDICIONES_POR_N_EXACTO));

  for (int i = 0; i < CANT_MEDICIONES_POR_N_EXACTO; ++i)
  {
    srand(1234235);
    for (int n = n_min; n < n_max + 1; ++n)
    {
      cout << n << endl;
      int m = 0.8 * cant_aristas_K_n(n);
      int max_w1 = 10000;
      int max_w2 = 10000;
      int K = 1 * ((1.0l * n * max_w1) / 4.0);
      entrada e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);

      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
      cacm_exacto::resolver(e);
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);

      mediciones_por_n[n - n_min][i] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);
    }
  }

  for (int n = n_min; n < n_max + 1; ++n)
  {
    sort(range(mediciones_por_n[n - n_min]));
    cout << n << " " << mediciones_por_n[n - n_min][CANT_MEDICIONES_POR_N_EXACTO/2] << endl;
  }
}

#define CANT_MEDICIONES_POR_N_GOLOSO 15

// gráfico tiempo vs n (para distintos m si queda bien)
void medir_goloso(int n_min, int n_max)
{
  timespec inicio, fin;
  vvlli mediciones_por_n(n_max - n_min + 1, vlli(CANT_MEDICIONES_POR_N_GOLOSO));

  for (int i = 0; i < CANT_MEDICIONES_POR_N_GOLOSO; ++i)
  {
    cout << i << endl;
    srand(123235);
    for (int n = n_min; n < n_max + 1; ++n)
    {
      int m = 1 * cant_aristas_K_n(n);
      int max_w1 = 10000;
      int max_w2 = 10000;
      int K = 1 * ((1.0l * n * max_w1) / 4.0);
      entrada e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);

      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
      cacm_goloso::resolver(e);
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);

      mediciones_por_n[n - n_min][i] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);
    }
  }

  for (int n = n_min; n < n_max + 1; ++n)
  {
    sort(range(mediciones_por_n[n - n_min]));
    cout << n << " " << mediciones_por_n[n - n_min][CANT_MEDICIONES_POR_N_GOLOSO/2] << endl;
  }
}

typedef long double ld;
typedef list<ld> lld;

void comparar_goloso_exacto_random(int n_min, int n_max)
{
  salida s_exacto, s_goloso;
  entrada e;
  lld ratios;
  ld prom_ratios;

  int seed = time(0);
  srand(seed);
  cout << "seed: " << seed << endl;

  for(int n = n_min; n < n_max + 1; ++n)
  {
    for (int i = 0; i < 100; ++i)
    {
      int m = 0.5 * cant_aristas_K_n(n);
      int max_w1 = 1000;
      int max_w2 = 1000;
      int K = 0.5 * ((1.0l * n * max_w1) / 4.0);
      entrada e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);

      s_exacto = cacm_exacto::resolver(e);
      s_goloso = cacm_goloso::resolver(e);
      if (s_exacto.hay_solucion)
        ratios.push_back(1.0l * s_goloso.W2 / s_exacto.W2);
    }
    prom_ratios = accumulate(range(ratios), 0.0l) / ratios.size();
    cout << n << " " << prom_ratios << endl;
  }
}

void medir_goloso_proporcion(int n_min, int n_max)
{
	cout << "Medicion goloso proporcion" << endl;
	salida s;
	entrada e;
	double proporcion;
	for(int i = n_min; i < n_max; i += 1 ){
		//cout << "n: " << i << endl;
		//cout << "i: " << (i-2)/3+1 << endl;
		entrada e = grafo_rompe_goloso(i,i - (i % 10));

    
    //cout << "goloso" << endl;
    s = cacm_goloso::resolver(e);
    //escribir_salida(s);
    //cout << endl;	
		proporcion = s.W2;
		
		//cout << "exacto" << endl;
    s = cacm_exacto::resolver(e);
    //escribir_salida(s);
    //cout << endl;
		proporcion /= s.W2;
		
		cout << i << " " << proporcion << endl;
		
	}
}


#define CANT_MEDICIONES_POR_N_BUSQ 15

void medir_busq_local_tiempo(int n_min, int n_max)
{
	cout << "Medicion busq local tiempo" << endl;
  timespec inicio, fin;
  vvlli mediciones_por_n(n_max - n_min + 1, vlli(CANT_MEDICIONES_POR_N_BUSQ));
	srand(1234235);
	cout << "datos_m = [";
		
		for (int i = 0; i < CANT_MEDICIONES_POR_N_BUSQ; ++i)
		{				
			for (int n = n_min; n < n_max + 1; ++n)
			{
			  int m = 0.8 * cant_aristas_K_n(n);
			  int max_w1 = 10000;
			  int max_w2 = 10000;
			  int K = 1 * ((1.0l * n * max_w1) / 4.0);
			  entrada e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);

			  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
			  cacm_busq_local::resolver(e);
			  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);

			  mediciones_por_n[n - n_min][i] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);
			}
		}
		for (int n = n_min; n < n_max + 1; ++n)
		{
		 	sort(range(mediciones_por_n[n - n_min]));
		 	cout << n << " " << mediciones_por_n[n - n_min][CANT_MEDICIONES_POR_N_BUSQ/2] << endl;
		}
		cout << "]; " << endl;
  
}

void medir_busq_local_calidad(int n_min, int n_max)
{
	cout << "Medicion busq local calidad" << endl;
  timespec inicio, fin;
  vvlli mediciones_por_n(n_max - n_min + 1, vlli(CANT_MEDICIONES_POR_N_BUSQ));
	srand(1234235);
	cout << "datos_m = [";
		
		for (int i = 0; i < CANT_MEDICIONES_POR_N_BUSQ; ++i)
		{				
			for (int n = n_min; n < n_max + 1; ++n)
			{
			  int m = 0.8 * cant_aristas_K_n(n);
			  int max_w1 = 10000;
			  int max_w2 = 10000;
			  int K = 1 * ((1.0l * n * max_w1) / 4.0);
			  entrada e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);

			  salida s1 = cacm_busq_local::resolver(e);
				
				
			  mediciones_por_n[n - n_min][i] = s1.W2;
			}
		}
		for (int n = n_min; n < n_max + 1; ++n)
		{
		 	sort(range(mediciones_por_n[n - n_min]));
		 	cout << n << " " << mediciones_por_n[n - n_min][CANT_MEDICIONES_POR_N_BUSQ/2] << endl;
		}
		cout << "]; " << endl;
  
}

void medir_busq_local_proporcion(int n_min, int n_max)
{
	cout << "Medicion busq local proporcion" << endl;
	salida s;
	entrada e;
	double proporcion;
	for(int i = n_min; i < n_max; i += 1 ){
		//cout << "n: " << i << endl;
		//cout << "i: " << (i-2)/3+1 << endl;
		entrada e = grafo_rompe_goloso(i,i*i);

    
    //cout << "goloso" << endl;
    s = cacm_busq_local::resolver(e);
    //escribir_salida(s);
    //cout << endl;	
		proporcion = s.W2;
		
		//cout << "exacto" << endl;
    s = cacm_exacto::resolver(e);
    //escribir_salida(s);
    //cout << endl;
		proporcion /= s.W2;
		
		cout << i << " " << proporcion << endl;
		
	}
}

void medir_busq_local_proporcion2(int n_inicio, int n_max){
  salida s;
  entrada e;
  double proporcion,proporcion2;
  for(int i = n_inicio; i < n_max; i += 1 ){
    cout  << i << " ";
    //cout << "i: " << (i-2)/3+1 << endl;
    entrada e = grafo_rompe_goloso2(i,i);

    
    s = cacm_goloso::resolver(e);
    //cout << "goloso" << endl;
    //escribir_salida(s);
    //cout << endl; 
    proporcion = s.W2;

    s = cacm_busq_local::resolver(e);
    // cout << "busqueda local" << endl;
    // escribir_salida(s);
    // cout << endl; 
    proporcion2 = s.W2;
    
    s = cacm_exacto::resolver(e);
    //cout << "exacto" << endl;
    //escribir_salida(s);
    //cout << endl;
    proporcion /= s.W2;
    proporcion2 /= s.W2;

    cout << proporcion  << " ";
    cout  << proporcion2  << endl;
  }


}

#define CANT_MEDICIONES_POR_N_GRASP 15

void comparar_grasp_coef(int n_min, int n_max)
{
  cout << fixed << setprecision(4);

  entrada e;
  salida s0, s1, s2, s3;
  lld ratios10, ratios20;
  ld prom_ratios10, prom_ratios20;
  
  int seed = time(0);
  //int seed = 1403878979;
  srand(seed);
  cout << "seed: " << seed << endl;
  for(int n = n_min; n < n_max + 1; ++n)
  {
    ratios10.clear();
    ratios20.clear();
    for (int i = 0; i < 10; ++i)
    {
      int m = 0.5 * cant_aristas_K_n(n);
      int max_w1 = 10000;
      int max_w2 = 10000;
      int K = 1 * ((1.0l * n * max_w1) / 4.0);
      entrada e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);
      
      s0 = cacm_grasp::resolver(e, 0.5, 50, 0.0001);
      s1 = cacm_grasp::resolver(e, 0.5, 51, 0.0001);

      if (s0.hay_solucion and s1.hay_solucion)
        cout << s0.W2 << " " << s1.W2 << endl;
      //   ratios10.push_back(1.0l * s1.W2 / s0.W2);
    }

    //prom_ratios10 = accumulate(range(ratios10), 0.0l) / ratios10.size();
    //cout << n << " " << prom_ratios10 << endl;
  }
}


void medir_grasp_intmax(int n_min, int n_max)
{/*
	cout << "Medicion grasp intmax" << endl;
	srand(1234235);
	cout << "datos_m = [";
	vector < vvlli > mediciones_por_n(vvlli(n_max - n_min + 1, vlli(CANT_MEDICIONES_POR_N_GRASP)));
		for (int i = 0; i < CANT_MEDICIONES_POR_N_GRASP; ++i)
		{				
			for (int n = n_min; n < n_max + 1; ++n)
			{
			  int m = 0.8 * cant_aristas_K_n(n);
			  int max_w1 = 10000;
			  int max_w2 = 10000;
			  int K = 1 * ((1.0l * n * max_w1) / 4.0);
			  entrada e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);

			  salida s1 = cacm_busq_local::resolver(e);
				salida s2 = cacm_busq_local::resolver(e);
				salida s3 = cacm_busq_local::resolver(e);
			  mediciones_por_n[1][n - n_min][i] = s1.W2;
			  mediciones_por_n[2][n - n_min][i] = s2.W2;	
			  mediciones_por_n[3][n - n_min][i] = s3.W2;
			}
		}
		for (int n = n_min; n < n_max + 1; ++n)
		{
		 	sort(range(mediciones_por_n[n - n_min]));
		 	cout << n << " " << mediciones_por_n[n - n_min][CANT_MEDICIONES_POR_N_GRASP/2] << endl;
		}
		cout << "]; " << endl;
  */
}

void medir_grasp_proporcion_solucion_inicial(int n_min, int n_max)
{
  cout << fixed << setprecision(4);

  entrada e;
  salida s0, s1;
  lld ratios;
  ld prom_ratios;
  
  int seed = time(0);
  //int seed = 1403878979;
  srand(seed);
  cout << "seed: " << seed << endl;
  for(int n = n_min; n < n_max + 1; ++n)
  {
    ratios.clear();
    for (int i = 0; i < 10; ++i)
    {
      int m = 0.5 * cant_aristas_K_n(n);
      int max_w1 = 10000;
      int max_w2 = 10000;
      int K = 1 * ((1.0l * n * max_w1) / 4.0);
      entrada e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);
      
      s0 = cacm_grasp::resolver(e, 0.5, 50, 0.0001);
      s1 = cacm_grasp::resolver(e, 0.5, 51, 0.0001);

      if (s0.hay_solucion and s1.hay_solucion)
        ratios.push_back(1.0l * s1.W2 / s0.W2);
    }
    
    prom_ratios = accumulate(range(ratios), 0.0l) / ratios.size();
    cout << n << " " << prom_ratios << endl;
  }
}
#define CANT_MEDICIONES_POR_N_TODOS 11

void medir_proporcion_todos_caminos(int n_inicio, int n_max){
  salida s;
  entrada e;
  timespec inicio, fin;
  vector<vvlli> mediciones_por_n(4, vvlli((n_max - n_inicio)/3, vlli(CANT_MEDICIONES_POR_N_TODOS)));
  double proporcion,proporcion2,proporcion3;
	for(int k = 0; k < CANT_MEDICIONES_POR_N_TODOS ; k++){
		for(int i = n_inicio; i < n_max; i += 3 ){
		  //cout  << i << " ";
		  //cout << "i: " << (i-2)/3+1 << endl;
		  entrada e = grafo_rompe_goloso2(i,i);
		  
		  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
			s = cacm_goloso::resolver(e);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);

			mediciones_por_n[0][(i-n_inicio)/3][k] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);
		  
		  //cout << "goloso" << endl;
		  //escribir_salida(s);
		  //cout << endl; 
		  proporcion = s.W2;
		
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
		  s = cacm_busq_local::resolver(e);
		  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);

			mediciones_por_n[1][(i-n_inicio)/3][k] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);
		  // cout << "busqueda local" << endl;
		  // escribir_salida(s);
		  // cout << endl; 
		  proporcion2 = s.W2;
		  
		  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
		  s = cacm_grasp::resolver(e,1);
		  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);

			mediciones_por_n[2][(i-n_inicio)/3][k] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);
		  // cout << "busqueda local" << endl;
		  // escribir_salida(s);
		  // cout << endl; 
		  proporcion3 = s.W2;
		  
		  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
		  s = cacm_exacto::resolver(e);
		  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);

			mediciones_por_n[3][(i-n_inicio)/3][k] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);
		  //cout << "exacto" << endl;
    //escribir_salida(s);
    //cout << endl;
    }
   }
    for(int k=0; k<4; k++){
		  for (int n = 0; n < (n_max - n_inicio)/3; ++n)
			{
			 	sort(range(mediciones_por_n[k][n]));
			 	cout << " " << mediciones_por_n[k][n][CANT_MEDICIONES_POR_N_BUSQ/2];
			}
			cout << endl;
		}
  


}

void medir_proporcion_todos_caminos_puentes(int n_inicio, int n_max){
  salida s;
  entrada e;
  double proporcion,proporcion2,proporcion3;
  for(int i = n_inicio; i < n_max; i += 3 ){
    cout  << i << " ";
    //cout << "i: " << (i-2)/3+1 << endl;
    entrada e = grafo_rompe_goloso2(i,i);
    
    s = cacm_goloso::resolver(e);
    //cout << "goloso" << endl;
    //escribir_salida(s);
    //cout << endl; 
    proporcion = s.W2;

    s = cacm_busq_local::resolver(e);
    // cout << "busqueda local" << endl;
    // escribir_salida(s);
    // cout << endl; 
    proporcion2 = s.W2;
    
    s = cacm_grasp::resolver(e);
    // cout << "busqueda local" << endl;
    // escribir_salida(s);
    // cout << endl; 
    proporcion3 = s.W2;
    
    s = cacm_exacto::resolver(e);
    //cout << "exacto" << endl;
    //escribir_salida(s);
    //cout << endl;
    proporcion /= s.W2;
    proporcion2 /= s.W2;
    proporcion3 /= s.W2;

    cout << proporcion  << " ";
    cout << proporcion2  << " ";
    cout  << proporcion3  << endl;
  }
}

void medir_calidad_todos()
{
  cout << fixed << setprecision(4);

  entrada e;
  salida s0, s1, s2, s3;
  lld ratios_1, ratios_2, ratios_3;
  ld prom_ratios_1, prom_ratios_2, prom_ratios_3;
  
  int seed = time(0);
  //int seed = 1403878979;
  srand(seed);
  cout << "seed: " << seed << endl;
  cout << "m = 0.8" << endl;
  cout << "K = 0.2" << endl;

  int n_min = 60, n_max = 110;
  for(int n = n_min; n < n_max + 1; ++n)
  {
    ratios_1.clear();
    ratios_2.clear();
    ratios_3.clear();
    for (int i = 0; i < 10; ++i)
    {
      int m = 0.8 * cant_aristas_K_n(n);
      int max_w1 = 10000;
      int max_w2 = 10000;
      int K = 0.2 * ((1.0l * n * max_w1) / 4.0);
      entrada e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);
      
      s0 = cacm_goloso::resolver(e);
      s1 = cacm_busq_local::resolver(e);
      s2 = cacm_grasp::resolver(e, 1, 20, 0.01);

      if (s0.hay_solucion and s1.hay_solucion and s2.hay_solucion)
      {
        ratios_1.push_back(1.0l * s0.W2 / (s0.W2 + s1.W2 + s2.W2));
        ratios_2.push_back(1.0l * s1.W2 / (s0.W2 + s1.W2 + s2.W2));
        ratios_3.push_back(1.0l * s2.W2 / (s0.W2 + s1.W2 + s2.W2));
   		}
   }

    prom_ratios_1 = accumulate(range(ratios_1), 0.0l) / ratios_1.size();
    cout << n << " " << (3 * prom_ratios_1) << " ";

    prom_ratios_2 = accumulate(range(ratios_2), 0.0l) / ratios_2.size();
    cout << (3 * prom_ratios_2) << " ";
    
    prom_ratios_3 = accumulate(range(ratios_3), 0.0l) / ratios_3.size();
    cout << (3 * prom_ratios_3) << endl;
  }
}

void medir_tiempo_todos(double _m, double _K)
{
  entrada e;
  salida s0, s1, s2, s3;
  lld ratios_1, ratios_2, ratios_3;
  ld prom_ratios_1, prom_ratios_2, prom_ratios_3;
  
  int seed = time(0);
  //int seed = 1403878979;
  cout << "seed: " << seed << endl;
  cout << "m = " << _m << endl;
  cout << "K = " << _K << endl;

  int n_min = 60, n_max = 110;

  timespec inicio, fin;
  typedef vector<long long int> vi;
  typedef vector<vi> vvi;
  typedef vector<vvi> vvvi;
  vvvi mediciones_0(n_max - n_min + 1, vvi(10, vi(5)));
  vvvi mediciones_1(n_max - n_min + 1, vvi(10, vi(5)));
  vvvi mediciones_2(n_max - n_min + 1, vvi(10, vi(5)));

  for (int med = 0; med < 5; ++med)
  {
    cout << "med" << " " << med << endl;
    srand(seed);
    for(int n = n_min; n < n_max + 1; ++n)
    {
      for (int i = 0; i < 10; ++i)
      {
        int m = _m * cant_aristas_K_n(n);
        int max_w1 = 10000;
        int max_w2 = 10000;
        int K = _K * ((1.0l * n * max_w1) / 4.0);
        entrada e = generar_instancia_aleatoria(n, m, max_w1, max_w2, K);
        
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
        s0 = cacm_goloso::resolver(e);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);
        mediciones_0[n - n_min][i][med] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
        s1 = cacm_busq_local::resolver(e);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);
        mediciones_1[n - n_min][i][med] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
        s2 = cacm_grasp::resolver(e, 1, 20, 0.01);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin);
        mediciones_2[n - n_min][i][med] = (fin.tv_sec - inicio.tv_sec) * 1e9 + (fin.tv_nsec - inicio.tv_nsec);
     }
    }
  }

  for(int n = n_min; n < n_max + 1; ++n)
  {
    for (int i = 0; i < 10; ++i)
    {
      sort(range(mediciones_0[n-n_min][i]));
      sort(range(mediciones_1[n-n_min][i]));
      sort(range(mediciones_2[n-n_min][i]));
    }
    
    long long int mediana_prom_0 = 0, mediana_prom_1 = 0, mediana_prom_2 = 0;
    for (int i = 0; i < 10; ++i)
    {
      mediana_prom_0 += mediciones_0[n-n_min][i][5/2];
      mediana_prom_1 += mediciones_1[n-n_min][i][5/2];
      mediana_prom_2 += mediciones_2[n-n_min][i][5/2];
    }
    cout << n << " " << (mediana_prom_0/10) << " " << (mediana_prom_1/10) << " " << (mediana_prom_2/10) << endl;
  }
}

int main(int argc, char const *argv[])
{
  // medir_grasp_calidad_aleatorios();
  //medir_exacto(3, 13);
  //medir_goloso_proporcion(5, 100);
  //medir_busq_local_tiempo(5, 100);
  //medir_busq_local_calidad(5, 100);
  //medir_busq_local_proporcion(5, 100);
  //medir_busq_local_proporcion2(8, 50);
  //medir_grasp_intmax(5,100);
  //comparar_grasp_coef(5,50);
  //medir_proporcion_todos_caminos(89,98);
  //medir_proporcion_todos_caminos_puentes(8,100);
  // medir_tiempo_todos(5,100);
  //medir_grasp_proporcion_solucion_inicial(5, 100);
  //medir_tiempo_todos();
  medir_tiempo_todos(0.8, 0.2);
  medir_tiempo_todos(0.8, 1.2);
  medir_tiempo_todos(0.4, 0.2);
  medir_tiempo_todos(0.4, 1.2);
  return 0;
}
