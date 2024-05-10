clc
clear
close all

s = tf('s');
t = 0:0.01:100; 
K = 189;
G = (K.*(s+12))/((s+14)*(s+18));
T = feedback(G,1);
 
figure();
kp = dcgain(G);
Estep = 1/(1+kp);
step (T,t), grid on;
xlabel('Time');
ylabel('Amplitude');
title('Step Response');
