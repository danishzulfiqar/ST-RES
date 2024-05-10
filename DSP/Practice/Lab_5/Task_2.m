% shifting property of DFT
clc
clear
close all

x = [1 2 3 4 5];
n = [0 1 2 3 4];

N = length(n);
l = -1;
xa = circshift(x,l);

Xk = fft(xa,N);
LHS = Xk;
RHS = fft(x,N) .* exp((-1i*(2*pi/N).*n*l));

subplot(2,1,1);
stem(n,real(LHS),'k','LineWidth',2);
title 'LHS'
xlabel 'Time --->';
ylabel 'Amplitude --->';

subplot(2,1,2);
stem(n,real(RHS),'r','LineWidth',2);
title 'RHS'
xlabel 'Time --->';
ylabel 'Amplitude --->';