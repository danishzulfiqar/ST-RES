% clc
% clear
% close all

den=[1 2 4];
num = [1 4];

G1 = tf([num],[den]);
step(G1);

hold on
num = [-1 4];
G2 = tf([num],[den]);
step(G2);

hold on
num = [1 -4];
G3 = tf([num],[den]);
step(G3)
legend("G1","G2","G3");

figure()
subplot(3,1,1)
pzmap(G1)
title("G1");

subplot(3,1,2)
pzmap(G2);
title("G2");

subplot(3,1,3);
pzmap(G3);
title("G3");