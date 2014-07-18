close all;

datos_tiempo1 = [ 37207 60666 84852 130329 166198 201417 253141 308054 413661 477078 562325 640561 733167 832105 934285 1048832 1160245 1286838 1415801 1546400 1690690 1836067 1807970 1965958 2124337 2247341 2403676 2581319 2743244 2905480 3095968
 38408 62439 87436 133017 162161 205171 257146 312575 410292 482575 563710 647046 739541 836276 943522 1060256 1170540 1287677 1426101 1556762 1701669 1848738 1818900 1960298 2140684 2282067 2419974 2583722 2769369 2918939 3110381
 1357637 2310216 3563908 5077574 6769323 8623940 10601102 13253253 15876625 18763267 21383416 24930113 28542117 32479498 35733967 40261246 44880956 49107835 53853875 60476795 65646195 71984041 77549046 82072825 89742096 96034515 101559603 108834278 116533942 123381426 134072679
 3151 4454 5747 7050 8341 9657 10942 12246 13553 14868 16158 17517 18840 20151 21459 22750 24161 25432 30020 28041 29404 30720 32045 34167 34675 35950 37284 38571 39922 41209 42514];
datos_tiempo1 = datos_tiempo1 ./ 1E6;
datos_tiempo2 = [ 67853 88938 136634 167144 212092 266798 323867 424843 502935 587466 675864 769112 870151 979975 1098387 1212839 1344274 1477919 1616540 1766728 1919540 1889612 2051871 2193257 2349146 2514551
 71879 99621 153383 190467 243155 306010 373801 484882 572681 667838 770802 880441 1005257 1123458 1254178 1400584 1539450 1699848 1859951 2034031 2222056 2204085 2386545 2561540 2744921 2955540
 2446993 3719207 5428894 7345200 9360927 11879778 14436164 17439216 20679448 23889075 28085899 32087028 35887924 40474498 44827793 50068341 55068757 60427028 65854280 72339680 77695694 84778235 92047742 99208018 105592238 114699791
 6951 12919 22651 45586 79524 158120 273445 539227 945838 1835565 3216171 6237654 10990278 21174917 37549701 71771649 128037155 244692160 436517222 821237489 1484636200 2786206514 5044780690 9443810733 17092007175 31954339880];
datos_tiempo2 = datos_tiempo2 ./ 1E9;

 figure;
  plot(8:3:100, datos_tiempo1(1,:), 'r');
  hold on;
  plot(8:3:100, datos_tiempo1(2,:), 'b');
  plot(8:3:100, datos_tiempo1(3,:), 'g');
  plot(8:3:100, datos_tiempo1(4,:), 'c');
  title('Tiempo de ejecucion algoritmos con familia 3-caminos.');
  xlabel('Cantidad de vertices (n)');
  ylabel('Tiempo (ms)');
  hleg = legend({'Goloso', 'Busq Local','Grasp','Exacto'});
  set(hleg, 'Position', [0.2 0.55 0.3 0.3]);
  set(get(hleg,'Title'),'String','Algoritmos');
  saveas(gca, ['../graficos/todos_tiempo_3caminos.eps'],'epsc');
  
  
  figure;
  plot(8:3:100, datos_tiempo1(1,:), 'r');
  hold on;
  plot(8:3:100, datos_tiempo1(2,:), 'b');
  plot(8:3:100, datos_tiempo1(4,:), 'c');
  title('Tiempo de ejecucion algoritmos con familia 3-caminos.');
  xlabel('Cantidad de vertices (n)');
  ylabel('Tiempo (ms)');
  hleg = legend({'Goloso', 'Busq Local','Exacto'});
  set(hleg, 'Position', [0.2 0.55 0.3 0.3]);
  set(get(hleg,'Title'),'String','Algoritmos');
  saveas(gca, ['../graficos/todos_tiempo_3caminos_sinG.eps'],'epsc');
  
   figure;
  plot(11:3:86, datos_tiempo2(1,:), 'r');
  hold on;
  plot(11:3:86, datos_tiempo2(2,:), 'b');
  plot(11:3:86, datos_tiempo2(3,:), 'g');
  plot(11:3:86, datos_tiempo2(4,:), 'c');
  title('Tiempo de ejecucion algoritmos con familia 3-caminos con puentes.');
  xlabel('Cantidad de vertices (n)');
  ylabel('Tiempo (ms)');
  hleg = legend({'Goloso', 'Busq Local','Grasp','Exacto'});
  set(hleg, 'Position', [0.2 0.55 0.3 0.3]);
  set(get(hleg,'Title'),'String','Algoritmos');
  saveas(gca, ['../graficos/todos_tiempo_puentes.eps'],'epsc');
  
  datos_tiempo2 = datos_tiempo2 ./ 1E-3;
  figure;
  plot(11:3:86, datos_tiempo2(1,:), 'r');
  hold on;
  plot(11:3:86, datos_tiempo2(2,:), 'b');
  plot(11:3:86, datos_tiempo2(3,:), 'g');
  title('Tiempo de ejecucion algoritmos con familia 3-caminos con puentes.');
  xlabel('Cantidad de vertices (n)');
  ylabel('Tiempo (ms)');
  hleg = legend({'Goloso', 'Busq Local','Grasp'});
  set(hleg, 'Position', [0.2 0.55 0.3 0.3]);
  set(get(hleg,'Title'),'String','Algoritmos');
  saveas(gca, ['../graficos/todos_tiempo_puentes_sinE.eps'],'epsc');