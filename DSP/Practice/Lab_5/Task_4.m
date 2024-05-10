% circular convolution
clc
clear 
close all

x = [1 2 3 4 5];
h = [0 1 0 1 0];
n = [0 1 2 3 4];

N = length(n);
y = cconv(x,h,N);

subplot(2,2,1);
stem(n,x,'k','LineWidth',2);
title 'Input signal'
xlabel 'Time --->';
ylabel 'Amplitude --->';

subplot(2,2,2);
stem(n,h,'g','LineWidth',2);
title 'Impulse response signal'
xlabel 'Time --->';
ylabel 'Amplitude --->';

subplot(2,2,[3 4]);
stem(n,y,'r','LineWidth',2);
title 'Convoluted signal'
xlabel 'Time --->';
ylabel 'Amplitude --->';