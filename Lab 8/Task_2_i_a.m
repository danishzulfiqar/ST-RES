clc
clear
close all

s = tf('s'); 
t = 0:0.01:100; 
K = 1000;
G = (K.*(s+5))/(s*(s+6)*(s+7)*(s+8));
T = feedback(G,1);

figure();
ut= heaviside(t);
ramp = 20.*t.*ut; 
kv = dcgain(s.*G);
Eramp = 1/kv;
lsim(T,ramp,t), grid on;
xlabel('Time');
ylabel('Amplitude');
title('Ramp Response');
