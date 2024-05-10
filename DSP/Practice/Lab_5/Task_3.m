% duality property of DFT LHS RHS
clc
clear
close all

x = [1 2 3 4 5];
n = [0 1 2 3 4];

N = length(n);
xa = N*sigfold(x,n);
Xk = fft(xa,N);

LHS = abs(Xk);
RHS = abs(fft(x,N));

subplot(2,1,1);
stem(n,LHS,'k','LineWidth',2);
title 'LHS'
xlabel 'Time --->';
ylabel 'Amplitude --->';

subplot(2,1,2);
stem(n,RHS,'r','LineWidth',2);
title 'RHS'
xlabel 'Time --->';
ylabel 'Amplitude --->';