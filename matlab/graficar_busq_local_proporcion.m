function graficar_busq_local_proporcion()

  close all;

    datos_goloso = [5 25
6 36
7 49
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
  ylabel('Proporcion (W2/W2 exacto)');
  saveas(gca, ['../graficos/busq_local_proporcion.eps'],'epsc');
  
  
  figure;
  plot(datos(:,1), datos(:,2), 'r');
  hold on;
  plot(datos_goloso(:,1), datos_goloso(:,2), 'b');
  title('Proporcion entre la solucion de busqueda local y goloso.');
  hleg = legend({'Busqueda local', 'Goloso'});
  xlabel('Cantidad de vertices (n)');
  ylabel('Proporcion (W2/W2 exacto)');
  saveas(gca, ['../graficos/busq_local_proporcion_comparacion.eps'],'epsc');
  
  
end