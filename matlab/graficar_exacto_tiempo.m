function graficar_exacto_tiempo()

  close all;

  datos_m_1 = [3 3606
    4 3844
    5 9690
    6 32590
    7 98669
    8 502521
    9 4101944
    10 16456911
    11 86789551
    12 498525419
    13 1912806250];

  datos_m_0_8 = [3 2720
    4 2854
    5 5117
    6 13461
    7 66882
    8 130777
    9 280949
    10 2502321
    11 19823947
    12 117423142
    13 405581561];

  datos_m_0_5 = [3 1586
    4 1951
    5 4225
    6 3897
    7 7986
    8 30619
    9 63205
    10 193605
    11 169014
    12 1368933
    13 3882609];

  cc = lines(3);

  figure;
  plot(datos_m_0_5(:,1), datos_m_0_5(:,2), 'Color', cc(1,:));
  hold on;
  plot(datos_m_0_8(:,1), datos_m_0_8(:,2), 'Color', cc(2,:));
  plot(datos_m_1(:,1), datos_m_1(:,2), 'Color', cc(3,:));
  title('Algoritmo exacto. Tiempo de ejecucion vs n.');
  hleg = legend({'50%', '80%', '100%'});
  set(hleg, 'Position', [0.2 0.55 0.3 0.3]);
  set(get(hleg,'Title'),'String','# aristas / # aristas Kn');
  
  figure;
  semilogy(datos_m_0_5(:,1), datos_m_0_5(:,2), 'Color', cc(1,:));
  hold on;
  semilogy(datos_m_0_8(:,1), datos_m_0_8(:,2), 'Color', cc(2,:));
  semilogy(datos_m_1(:,1), datos_m_1(:,2), 'Color', cc(3,:));
  title('Algoritmo exacto. Tiempo de ejecucion vs n. Escala logaritmica');
  hleg = legend({'50%', '80%', '100%'});
  set(hleg, 'Position', [0.2 0.55 0.3 0.3]);
  set(get(hleg,'Title'),'String','# aristas / # aristas Kn');

end