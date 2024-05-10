clc
clear
close all

t = 0:0.01:10;
x = cos(2*pi*t);

figure(1);

subplot(2,1,1);
plot(t,x);


hold on
n = 0:10;
y = sin(n);
subplot(2,1,2);
stem(n,y);