function graficar_todos_tiempo_v2()

% seed: 1405374434
% m = 0.8
% K = 0.2
% med 0
% med 1
% med 2
% med 3
% med 4
datos = [60 1656153 1668334 63921122
61 2091958 2096458 70031266
62 2219625 2218900 76565246
63 1676697 1668815 65926430
64 2044310 2031835 73615870
65 2281085 2272821 82786882
66 1788851 1784987 68401044
67 2291859 2283788 82400780
68 2875356 2869048 101831774
69 2547802 2531847 91091002
70 1867679 1855053 67387386
71 2617754 2634138 92620399
72 2392029 2409700 91697841
73 2952461 2970168 104328597
74 2733397 2755832 103294097
75 2361279 2376249 88416851
76 2643078 2671746 107642571
77 2424709 2444282 100064968
78 3152050 3177801 124172162
79 2748568 2727108 105241743
80 2935824 2914900 103498842
81 3008738 2989168 108836229
82 3544268 3525053 120629786
83 2909928 2890445 108637537
84 3650636 3631853 137591337
85 3760334 3727442 129079097
86 3319504 3338534 118469052
87 4086778 4117632 152431837
88 4230213 4253968 152719884
89 3173070 3200381 119538161
90 3942354 3968676 154400490
91 4868832 4898851 171753800
92 3386799 3358093 128508002
93 4620855 4596703 174160378
94 2740363 2704483 113250756
95 3539802 3507303 134632853
96 4083737 4051940 157244622
97 4646679 4610468 166372596
98 3636523 3593135 134749435
99 5404363 5438968 190352862
100 4593581 4624641 170537620
101 4461648 4493279 168258246
102 5435916 5466052 195917299
103 4777123 4809200 178071536
104 3513037 3490730 145519161
105 5346681 5309141 180738596
106 6707290 6673242 223522149
107 5960499 5924311 221416355
108 5577479 5532227 192994641
109 6630032 6580758 231526277
110 4443851 4470132 166932655];

figure; hold on;
plot(datos(:,1), datos(:,2), 'r');
plot(datos(:,1), datos(:,3), 'g');
plot(datos(:,1), 0.05*datos(:,4), 'b');