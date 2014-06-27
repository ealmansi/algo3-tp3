function graficar_todos_proporcion()

  close all;
    
  figure;
  bar(1:5:100, [1:5:100;1:5:100;ones(1,20)]');
  hold on;
  title('Proporcion entre la solucion de los diferentes algoritmos y el exacto (3-caminos).');
  axis([0,100,0,110]);
  hleg = legend({'Goloso','Busqueda Local','GRASP'});
  set(hleg, 'Position', [0.2 0.55 0.2 0.2]);
  xlabel('Cantidad de vertices (n)');
  ylabel('Proporcion (W2 / W2 exacto)');
  saveas(gca, ['../graficos/todos_proporcion_3caminos.eps'],'epsc');
  
  figure;
  bar(1:5:100, [1:5:100;ones(1,20);ones(1,20)]');
  hold on;
  title('Proporcion entre la solucion de los diferentes algoritmos y el exacto (3-caminos con puentes).');
  axis([0,100,0,110]);
  hleg = legend({'Goloso','Busqueda Local','GRASP'});
  set(hleg, 'Position', [0.2 0.55 0.2 0.2]);
  xlabel('Cantidad de vertices (n)');
  ylabel('Proporcion (W2 / W2 exacto)');
  saveas(gca, ['../graficos/todos_proporcion_puentes.eps'],'epsc');
  
 
  
end