close all;

datos_tiempo1 = [ 37207 60666 84852 130329 166198 201417 253141 308054 413661 477078 562325 640561 733167 832105 934285 1048832 1160245 1286838 1415801 1546400 1690690 1836067 1807970 1965958 2124337 2247341 2403676 2581319 2743244 2905480 3095968
 38408 62439 87436 133017 162161 205171 257146 312575 410292 482575 563710 647046 739541 836276 943522 1060256 1170540 1287677 1426101 1556762 1701669 1848738 1818900 1960298 2140684 2282067 2419974 2583722 2769369 2918939 3110381
 1357637 2310216 3563908 5077574 6769323 8623940 10601102 13253253 15876625 18763267 21383416 24930113 28542117 32479498 35733967 40261246 44880956 49107835 53853875 60476795 65646195 71984041 77549046 82072825 89742096 96034515 101559603 108834278 116533942 123381426 134072679
 3151 4454 5747 7050 8341 9657 10942 12246 13553 14868 16158 17517 18840 20151 21459 22750 24161 25432 30020 28041 29404 30720 32045 34167 34675 35950 37284 38571 39922 41209 42514];

datos_tiempo2 = [];
%%
 figure;
  plot(8:3:100, datos_tiempo1(1,:), 'r');
  hold on;
  plot(8:3:100, datos_tiempo1(2,:), 'b');
  plot(8:3:100, datos_tiempo1(3,:), 'g');
  plot(8:3:100, datos_tiempo1(4,:), 'y');
  title('Tiempo de ejecucion algoritmos con familia 3-caminos.');
  xlabel('Cantidad de vertices (n)');
  ylabel('Tiempo (ns)');
  hleg = legend({'Goloso', 'Busq Local','Grasp','Exacto'});
  set(hleg, 'Position', [0.2 0.55 0.3 0.3]);
  set(get(hleg,'Title'),'String','Algoritmos');
  saveas(gca, ['../graficos/todos_tiempo_3caminos.eps'],'epsc');
  
  
  figure;
  plot(8:3:100, datos_tiempo1(1,:), 'r');
  hold on;
  plot(8:3:100, datos_tiempo1(2,:), 'b');
  plot(8:3:100, datos_tiempo1(4,:), 'y');
  title('Tiempo de ejecucion algoritmos con familia 3-caminos.');
  xlabel('Cantidad de vertices (n)');
  ylabel('Tiempo (ns)');
  hleg = legend({'Goloso', 'Busq Local','Exacto'});
  set(hleg, 'Position', [0.2 0.55 0.3 0.3]);
  set(get(hleg,'Title'),'String','Algoritmos');
  saveas(gca, ['../graficos/todos_tiempo_3caminos_sinG.eps'],'epsc');
  
%%  
  figure;
  plot(datos_m_gol(:,1), datos_m_gol(:,2) / 10, 'r');
  hold on;
  plot(datos_m_dij(:,1), datos_m_dij(:,2), 'b');
  title('Tiempo de ejecucion algoritmo de busqueda local.');
  xlabel('Cantidad de vertices (n)');
  ylabel('Tiempo (ns)');
  hleg = legend({'Goloso / cant iteraciones', 'Dijkstra'});
  set(hleg, 'Position', [0.2 0.55 0.3 0.3]);
  set(get(hleg,'Title'),'String','Solucion inicial');
  saveas(gca, ['../graficos/busq_local_tiempo_divido10.eps'],'epsc');  