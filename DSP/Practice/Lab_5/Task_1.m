% Circular Shift
clc
close all
clear

n= -2:2;
x= [3 6 8 9 2];
k= 2;

figure (1)
stem(n,x)
title('Original input signal')
xlabel 'Time'
ylabel 'Amplitude'

figure(2)
[x_new] = circularshift(x,n);
stem (n,x_new)
title('Circularly shifted signal')
xlabel 'Time'
ylabel 'Amplitude'