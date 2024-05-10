clc
clear 
close all

G1 = tf([1],[1 1]); 
G2 = tf([1],[2 1]); 
G3 = tf([1],[3 1]); 
 
[x, t] = step(G1); 
plot(t, x, 'linewidth', 2); 
grid on;
xlabel('Time');
ylabel('Amplitude');
title('Step Responses using Step Command');

hold on;

[x1, t] = step(G2);
plot(t, x1, 'linewidth', 2); 

[x2, t] = step(G3); 
plot(t, x2, 'linewidth', 2);

legend('G1', 'G2', 'G3');

hold off;

t = 0:0.01:10;
u = ones(size(t));
[y1, t] = lsim(G1, u, t); 
[y2, t] = lsim(G2, u, t); 
[y3, t] = lsim(G3, u, t);  

figure();

plot(t, y1, 'linewidth', 2); 
grid on;
xlabel('Time');
ylabel('Amplitude');
title('Step Response using lsim of G1');

hold on;

plot(t, y2, 'linewidth', 2); 

plot(t, y3, 'linewidth', 2);

legend('G1', 'G2', 'G3');

hold off;
