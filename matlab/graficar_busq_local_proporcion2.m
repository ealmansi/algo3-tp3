function graficar_busq_local_proporcion2()

  close all;

    datos = [8 8 1
9 9 1
10 10 1
11 11 1
12 12 1
13 13 1
14 14 1
15 15 1
16 16 1
17 17 1
18 18 1
19 19 1
20 20 1
21 21 1
22 22 1
23 23 1
24 24 1
25 25 1
26 26 1
27 27 1
28 28 1
29 29 1
30 30 1
31 31 1
32 32 1
33 33 1
34 34 1
35 35 1
36 36 1
37 37 1
38 38 1
39 39 1
40 40 1
41 41 1
42 42 1
43 43 1
44 44 1
45 45 1
46 46 1
47 47 1
48 48 1
49 49 1

];
  
 

  
  figure;
  plot(datos(:,1), datos(:,3), 'r');
  hold on;
  plot(datos(:,1), datos(:,2), 'b');
  title('Proporcion entre la solucion de busqueda local y goloso.');
  hleg = legend({'Busqueda local', 'Goloso'});
  xlabel('Cantidad de vertices (n)');
  ylabel('Proporcion (W2/W2 exacto)');
  saveas(gca, ['../graficos/busq_local_proporcion2.eps'],'epsc');
  
  
end