function graficar_busq_local_proporcion()

  close all;

  datos = [5 1
6 1
7 1
8 64
9 81
10 100
11 121
12 144
13 169
14 196
15 225
16 256
17 289
18 324
19 361
20 400
21 441
22 484
23 529
24 576
25 625
26 676
27 729
28 784
29 841
30 900];


  figure;
  plot(datos(:,1), datos(:,2), 'r');
  hold on;
  title('Proporcion entre la solucion de busqueda local y la exacta.');
  xlabel('Cantidad de vertices (n)');
  ylabel('Proporcion');
  saveas(gca, ['../graficos/busq_local_proporcion.eps'],'epsc');
  
  
  
end