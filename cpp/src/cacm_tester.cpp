#include "cacm.h"
#include "cacm_exacto.h"
#include "cacm_goloso.h"
#include "cacm_busq_local.h"
#include "cacm_grasp.h"
using namespace cacm;

#include <iostream>
#include <cstdlib>
#include <set>
#include <math.h>
using namespace std;

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

void Test_rompe_goloso(int n, int intervalo){
	salida s;
	entrada e;
	double proporcion;
	for(int i = 5; i < n; i += intervalo ){
		cout << "n: " << i << endl;
		//cout << "i: " << (i-2)/3+1 << endl;
		entrada e = grafo_rompe_goloso(i,i*i);

    
    cout << "goloso" << endl;
    s = cacm_goloso::resolver(e);
    escribir_salida(s);
    cout << endl;	
		proporcion = s.W2;
		
		cout << "exacto" << endl;
    s = cacm_exacto::resolver(e);
    escribir_salida(s);
    cout << endl;
		proporcion /= s.W2;
		
		cout << "Proporcion: " << proporcion << endl;
		
	}


}

void Test_rompe_goloso2(int n, int intervalo){
  salida s;
  entrada e;
  double proporcion,proporcion2;
  for(int i = 8; i < n; i += intervalo ){
    cout << "n: " << i << endl;
    //cout << "i: " << (i-2)/3+1 << endl;
    entrada e = grafo_rompe_goloso2(i,i*i);

    
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

    cout << "Proporcion 1: " << proporcion  << endl;
    cout << "Proporcion 2: " << proporcion2  << endl << endl;
  }


}


void Test_grasp(int n, int intervalo){
	salida s;
	entrada e;
	double proporcion;
	for(int i = 8; i < n; i += intervalo ){
		cout << "n: " << i << endl;
		//cout << "i: " << (i-2)/3+1 << endl;
		entrada e = grafo_rompe_goloso(i,i*i);

    
    //cout << "grasp" << endl;
    s = cacm_grasp::resolver(e);
    //escribir_salida(s);
    //cout << endl;	
		proporcion = s.W2;
		
		//cout << "exacto" << endl;
    s = cacm_exacto::resolver(e);
    //escribir_salida(s);
    //cout << endl;
		proporcion /= s.W2;
		
		cout << "Proporcion: " << proporcion << endl;
		
	}


}

void Test_grasp_puentes(int n, int intervalo){
	salida s;
	entrada e;
	double proporcion;
	for(int i = 101; i < n; i += intervalo ){
		cout << "n: " << i << endl;
		//cout << "i: " << (i-2)/3+1 << endl;
		entrada e = grafo_rompe_goloso2(i,i*i);

    
    //cout << "grasp" << endl;
    s = cacm_grasp::resolver(e,30,40,0.1);
    //escribir_salida(s);
    //cout << endl;	
		proporcion = s.W2;
		
		//cout << "exacto" << endl;
    s = cacm_exacto::resolver(e);
    //escribir_salida(s);
    //cout << endl;
		proporcion /= s.W2;
		
		cout << "Proporcion: " << proporcion << endl;
		
	}


}

int main(int argc, char const *argv[])
{
  
  //Test_rompe_goloso2(40,3);
  //Test_grasp(1000,3);
  Test_grasp_puentes(102,3);
  /*entrada e = grafo_rompe_goloso(9,100);
  salida s;
   cout << "exacto" << endl;
    s = cacm_exacto::resolver(e);
    escribir_salida(s);
    cout << endl;

    cout << "goloso" << endl;
    s = cacm_goloso::resolver(e);
    escribir_salida(s);
    cout << endl;
  */
  /*
  for (int i = 0; i < 1; ++i)
  {
    
    entrada e = grafo_rompe_goloso(200,7000);
    //entrada e = generar_instancia_aleatoria(15, 30, 100, 100, 50);

    salida s;

    cout << "exacto" << endl;
    s = cacm_exacto::resolver(e);
    escribir_salida(s);
    cout << endl;

    cout << "goloso" << endl;
    s = cacm_goloso::resolver(e);
    escribir_salida(s);
    cout << endl;

    cout << "busq_local" << endl;
    s = cacm_busq_local::resolver(e);
    escribir_salida(s);
    cout << endl;

    cout << "grasp" << endl;
    s = cacm_grasp::resolver(e);
    escribir_salida(s);
    cout << endl;

    cout << "---------------" << endl;
  }
*/	
  return 0;
}
