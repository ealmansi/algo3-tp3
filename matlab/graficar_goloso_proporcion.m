function graficar_goloso_proporcion()

  close all;

  datos = [5 25
8 64
11 121
14 196
17 289
20 400
23 529
26 676
29 841
32 1024
35 1225
38 1444
41 1681
44 1936
47 2209
50 2500
53 2809
56 3136
59 3481
62 3844
65 4225
68 4624
71 5041
74 5476
77 5929
80 6400
83 6889
86 7396
89 7921
92 8464
95 9025
98 9604];

datos1 = [11 10
14 10
17 10
20 20
23 20
26 20
29 20
32 30
35 30
38 30
41 40
44 40
47 40
50 50
53 50
56 50
59 50
62 60
65 60
68 60
71 70
74 70
77 70
80 80
83 80
86 80
89 80
92 90
95 90
98 90];

  figure;
  plot(datos(:,1), datos(:,2), 'r');
  hold on;
  title('Proporcion entre la solucion golosa y la exacta.');
  xlabel('Cantidad de vertices (n)');
  ylabel('Proporcion');
  saveas(gca, ['../graficos/goloso_proporcion.eps'],'epsc');
  
  figure;
  plot(datos1(:,1), datos1(:,2), 'r');
  hold on;
  title('Proporcion entre la solucion golosa y la exacta.');
  xlabel('Cantidad de vertices (n)');
  ylabel('Proporcion');
  saveas(gca, ['../graficos/goloso_proporcion2.eps'],'epsc');
  
end