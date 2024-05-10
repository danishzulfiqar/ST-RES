clc
clear
close all

zeta = 0.7071; 
wn = 4.2426;   
frequency_input = 7; 

num = wn^2;
den = [1, 2 * zeta * wn, wn^2];
sys = tf(num, den);

t = linspace(0, 10*(2*pi)/frequency_input, 1000);
u = sin(frequency_input * t);

y = lsim(sys, u, t);

subplot(2,1,1);
plot(t, u);
title('Input Signal (sinusoidal)');
xlabel('Time (t)');
ylabel('Amplitude');
grid on;

subplot(2,1,2);
plot(t, y);
title('System Response');
xlabel('Time (t)');
ylabel('Amplitude');
grid on;
