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

datos1 = [10 10
11 10
12 10
13 10
14 10
15 10
16 10
17 10
18 10
19 10
20 20
21 20
22 20
23 20
24 20
25 20
26 20
27 20
28 20
29 20
30 30
31 30
32 30
33 30
34 30
35 30
36 30
37 30
38 30
39 30
40 40
41 40
42 40
43 40
44 40
45 40
46 40
47 40
48 40
49 40
50 50
51 50
52 50
53 50
54 50
55 50
56 50
57 50
58 50
59 50
60 60
61 60
62 60
63 60
64 60
65 60
66 60
67 60
68 60
69 60
70 70
71 70
72 70
73 70
74 70
75 70
76 70
77 70
78 70
79 70
80 80
81 80
82 80
83 80
84 80
85 80
86 80
87 80
88 80
89 80
90 90
91 90
92 90
93 90
94 90
95 90
96 90
97 90
98 90
99 90];

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