clc
clear
close all

t = 0:0.1:20;
G = tf([1],[1 1]);
u = sin(t);
response1 = lsim(G,u,t);

subplot(2,2,1);
plot(t, response1, 'linewidth', 2);
grid on;
xlabel('Time');
ylabel('Amplitude');
title('Response to Sinusoidal Input');

u1 = exp(-t);
response2 = lsim(G,u1,t);

subplot(2,2,2);
plot(t, response2, 'linewidth', 2);
grid on;
xlabel('Time');
ylabel('Amplitude');
title('Response to Exponential Input');

subplot(2,2,3);
step(G);

subplot(2,2,4);
impulse(G);
