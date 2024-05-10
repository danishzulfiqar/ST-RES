% Sampling Theorem
clc
clear
close all

t = -100:0.01:100;
T=30;
fm = 1/T;

x = cos(2*pi*fm*t);

subplot(2,2,1);
plot(t,x);
grid on;
xlabel('Time in seconds');
xlabel('x(t)');
title('Continuous time signal');

fs1 = 1.6*fm;
n1 = -5:1:5;
xn1 = cos(2*pi*n1*fm/fs1);

subplot(2,2,2);
stem(n1,xn1);
hold on;
plot(n1, xn1);
grid on;
xlabel('Time in seconds');
xlabel('x(t)');
title('Discrete time signal with fs1<2fm');

fs2 = 2*fm;
n2 = -5:1:5;
xn2 = cos(2*pi*n2*fm/fs2);

subplot(2,2,3);
stem(n2,xn2);
hold on;
plot(n2, xn2);
grid on;
xlabel('Time in seconds');
xlabel('x(t)');
title('Discrete time signal with fs2 = 2fm');

fs3 = 8*fm;
n3 = -20:1:20;
xn3 = cos(2*pi*n3*fm/fs3);

subplot(2,2,4);
stem(n3,xn3);
hold on;
plot(n3, xn3);
grid on;
xlabel('Time in seconds');
xlabel('x(t)');
title('Discrete time signal with fs1 > 2fm');

