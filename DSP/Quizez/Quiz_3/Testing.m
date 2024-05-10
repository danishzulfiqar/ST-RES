clc
clear
close all

n = -10:1:10;
x = cos(1*n);

fx =fft(x);

stem(n,abs(fx));
