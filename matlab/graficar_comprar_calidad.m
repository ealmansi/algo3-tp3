function graficar_comprar_calidad()

close all;

% int m = 0.8 * cant_aristas_K_n(n);
% int max_w1 = 10000;
% int max_w2 = 10000;
% int K = 1 * ((1.0l * n * max_w1) / 4.0);
datos = [60 1.0000 1.0000 1.0000
61 1.0000 1.0000 1.0000
62 1.0001 1.0001 0.9997
63 1.0000 1.0000 1.0000
64 0.9990 0.9990 1.0019
65 1.0000 1.0000 1.0000
66 1.0000 1.0000 1.0000
67 0.9971 0.9971 1.0058
68 1.0000 1.0000 1.0000
69 1.0000 1.0000 1.0000
70 1.0000 1.0000 1.0000
71 1.0000 1.0000 1.0000
72 1.0000 1.0000 1.0000
73 1.0000 1.0000 1.0000
74 1.0000 1.0000 1.0000
75 1.0000 1.0000 1.0000
76 1.0000 1.0000 1.0000
77 1.0003 1.0003 0.9994
78 1.0000 1.0000 1.0000
79 1.0000 1.0000 1.0000
80 1.0000 1.0000 1.0000
81 1.0000 1.0000 1.0000
82 1.0000 1.0000 1.0000
83 1.0000 1.0000 1.0000
84 0.9985 0.9985 1.0030
85 1.0000 1.0000 1.0000
86 1.0000 1.0000 0.9999
87 1.0000 1.0000 1.0000
88 1.0000 1.0000 1.0000
89 1.0000 1.0000 1.0000
90 1.0000 1.0000 1.0000
91 1.0000 1.0000 1.0000
92 1.0000 1.0000 1.0000
93 1.0000 1.0000 1.0000
94 1.0002 1.0002 0.9997
95 1.0000 1.0000 1.0000
96 1.0000 1.0000 1.0000
97 1.0002 1.0002 0.9996
98 1.0000 1.0000 1.0000
99 1.0000 1.0000 1.0000
100 1.0000 1.0000 1.0000
101 0.9969 0.9969 1.0063
102 1.0000 1.0000 1.0000
103 1.0000 1.0000 1.0000
104 1.0000 1.0000 1.0000
105 1.0000 1.0000 1.0000
106 1.0000 1.0000 1.0000
107 1.0000 1.0000 1.0000
108 1.0000 1.0000 1.0000
109 1.0000 1.0000 1.0000
110 1.0000 1.0000 1.0000];

figure; bar(datos(:,1), datos(:,2:4)  -1);
title('Comparacion de calidad sobre instancias aleatorios (m* = 0.8, K* = 1)');
ylabel('Desviacion respecto al promedio (W2 / W2 promedio  - 1)');
xlabel('Cantidad de nodos (n)');
legend({'Goloso', 'Busq local', 'GRASP'});
saveas(gca, ['../graficos/todos_calidad_m08_K1.eps'],'epsc');

%int m = 0.4 * cant_aristas_K_n(n);
%      int max_w1 = 10000;
%      int max_w2 = 10000;
%      int K = 0.2 * ((1.0l * n * max_w1) / 4.0);

datos = [60 1.0000 1.0000 1.0000
61 1.0000 1.0000 1.0000
62 1.0000 1.0000 1.0000
63 1.0000 1.0000 1.0000
64 1.0038 1.0038 0.9923
65 1.0000 1.0000 1.0000
66 1.0000 1.0000 1.0000
67 1.0000 1.0000 1.0000
68 1.0000 1.0000 1.0000
69 1.0242 1.0242 0.9517
70 1.0130 1.0130 0.9739
71 1.0011 1.0011 0.9977
72 1.0000 1.0000 1.0000
73 1.0000 1.0000 1.0000
74 1.0000 1.0000 1.0000
75 1.0015 1.0015 0.9970
76 1.0000 1.0000 1.0000
77 1.0000 1.0000 1.0000
78 1.0018 1.0018 0.9963
79 1.0000 1.0000 1.0000
80 1.0028 1.0028 0.9945
81 1.0000 1.0000 1.0000
82 1.0000 1.0000 1.0000
83 0.9927 0.9927 1.0146
84 1.0000 1.0000 1.0000
85 1.0000 1.0000 1.0000
86 1.0000 1.0000 1.0000
87 1.0000 1.0000 1.0000
88 1.0000 1.0000 1.0000
89 1.0000 1.0000 1.0000
90 1.0000 1.0000 1.0000
91 1.0000 1.0000 1.0000
92 1.0000 1.0000 1.0000
93 1.0000 1.0000 1.0000
94 1.0000 1.0000 1.0000
95 1.0000 1.0000 1.0000
96 1.0006 1.0006 0.9988
97 0.9995 0.9995 1.0010
98 1.0000 1.0000 1.0000
99 1.0000 1.0000 1.0000
100 1.0003 0.9999 0.9999
101 1.0000 1.0000 1.0000
102 1.0000 1.0000 1.0000
103 1.0000 1.0000 1.0000
104 1.0000 1.0000 1.0000
105 1.0000 1.0000 1.0000
106 1.0000 1.0000 1.0000
107 1.0000 1.0000 1.0000
108 1.0000 1.0000 0.9999
109 1.0000 1.0000 1.0000
110 1.0002 1.0002 0.9996];

figure; bar(datos(:,1), datos(:,2:4)  -1);
title('Comparacion de calidad sobre instancias aleatorios (m* = 0.4, K* = 0.2)');
ylabel('Desviacion respecto al promedio (W2 / W2 promedio  - 1)');
xlabel('Cantidad de nodos (n)');
legend({'Goloso', 'Busq local', 'GRASP'});
saveas(gca, ['../graficos/todos_calidad_m04_K02.eps'],'epsc');


%int m = 0.4 * cant_aristas_K_n(n);
%      int max_w1 = 10000;
%      int max_w2 = 10000;
%      int K = 1 * ((1.0l * n * max_w1) / 4.0);

datos = [60 1.0000 1.0000 1.0000
61 1.0000 1.0000 1.0000
62 0.9975 0.9975 1.0050
63 1.0000 1.0000 1.0000
64 1.0000 1.0000 1.0000
65 1.0000 1.0000 1.0000
66 0.9979 0.9979 1.0041
67 1.0000 1.0000 1.0000
68 1.0000 1.0000 1.0000
69 1.0000 1.0000 1.0000
70 1.0000 1.0000 1.0000
71 1.0000 1.0000 1.0000
72 0.9989 0.9989 1.0021
73 1.0000 1.0000 1.0000
74 0.9993 0.9993 1.0014
75 1.0000 1.0000 1.0000
76 0.9987 0.9987 1.0027
77 1.0000 1.0000 1.0000
78 1.0000 1.0000 1.0000
79 1.0000 1.0000 1.0000
80 1.0000 1.0000 1.0000
81 1.0000 1.0000 1.0000
82 1.0000 1.0000 1.0000
83 1.0000 1.0000 1.0000
84 1.0000 1.0000 1.0000
85 1.0000 1.0000 1.0000
86 1.0000 1.0000 1.0000
87 1.0000 1.0000 1.0000
88 1.0000 1.0000 1.0000
89 0.9968 0.9968 1.0065
90 1.0000 1.0000 1.0000
91 1.0000 1.0000 1.0000
92 1.0006 0.9997 0.9997
93 1.0000 1.0000 1.0000
94 1.0000 1.0000 1.0000
95 1.0001 1.0001 0.9998
96 1.0000 1.0000 1.0000
97 0.9926 0.9926 1.0148
98 1.0000 1.0000 1.0000
99 1.0000 1.0000 1.0000
100 1.0000 1.0000 1.0000
101 1.0000 1.0000 1.0000
102 0.9972 0.9972 1.0055
103 1.0000 1.0000 1.0000
104 1.0000 1.0000 1.0000
105 1.0000 1.0000 1.0000
106 1.0000 1.0000 1.0000
107 1.0000 1.0000 1.0000
108 1.0000 1.0000 1.0000
109 1.0000 1.0000 1.0000
110 1.0000 1.0000 1.0000];

figure; bar(datos(:,1), datos(:,2:4)  -1);
title('Comparacion de calidad sobre instancias aleatorios (m* = 0.4, K* = 1)');
ylabel('Desviacion respecto al promedio (W2 / W2 promedio  - 1)');
xlabel('Cantidad de nodos (n)');
legend({'Goloso', 'Busq local', 'GRASP'});
saveas(gca, ['../graficos/todos_calidad_m04_K1.eps'],'epsc');

%int m = 0.8 * cant_aristas_K_n(n);
%      int max_w1 = 10000;
%      int max_w2 = 10000;
%      int K = 0.2 * ((1.0l * n * max_w1) / 4.0);

datos = [60 1.0000 1.0000 1.0000
61 1.0000 1.0000 1.0000
62 1.0105 1.0105 0.9791
63 1.0000 1.0000 0.9999
64 1.0043 1.0043 0.9914
65 1.0096 1.0096 0.9808
66 1.0000 1.0000 1.0000
67 1.0000 1.0000 1.0000
68 1.0001 1.0001 0.9997
69 1.0000 1.0000 1.0000
70 1.0000 1.0000 1.0000
71 1.0000 1.0000 1.0000
72 1.0003 0.9999 0.9999
73 1.0009 1.0009 0.9982
74 1.0000 1.0000 1.0000
75 1.0000 1.0000 1.0000
76 0.9989 0.9989 1.0022
77 1.0003 1.0003 0.9995
78 1.0000 1.0000 1.0000
79 1.0000 1.0000 1.0000
80 1.0000 1.0000 1.0000
81 1.0000 1.0000 1.0000
82 1.0000 1.0000 1.0000
83 1.0008 1.0008 0.9984
84 1.0000 1.0000 1.0000
85 1.0011 1.0011 0.9978
86 1.0000 1.0000 1.0000
87 1.0029 1.0029 0.9942
88 1.0000 1.0000 1.0000
89 1.0000 1.0000 1.0000
90 0.9931 0.9931 1.0139
91 1.0017 1.0017 0.9966
92 1.0000 1.0000 1.0000
93 1.0000 1.0000 1.0000
94 1.0000 1.0000 1.0000
95 0.9979 0.9979 1.0042
96 1.0000 1.0000 1.0000
97 1.0007 1.0007 0.9987
98 1.0000 1.0000 1.0000
99 1.0006 0.9997 0.9997
100 1.0000 1.0000 1.0000
101 1.0000 1.0000 1.0000
102 1.0000 1.0000 1.0000
103 1.0000 1.0000 1.0000
104 1.0000 1.0000 1.0000
105 1.0000 1.0000 1.0000
106 1.0000 1.0000 1.0000
107 1.0002 1.0002 0.9995
108 1.0000 1.0000 1.0000
109 0.9994 0.9994 1.0011
110 1.0001 0.9999 0.9999];

figure; bar(datos(:,1), datos(:,2:4)  -1);
title('Comparacion de calidad sobre instancias aleatorios (m* = 0.8, K* = 0.2)');
ylabel('Desviacion respecto al promedio (W2 / W2 promedio  - 1)');
xlabel('Cantidad de nodos (n)');
legend({'Goloso', 'Busq local', 'GRASP'});
saveas(gca, ['../graficos/todos_calidad_m08_K02.eps'],'epsc');


end