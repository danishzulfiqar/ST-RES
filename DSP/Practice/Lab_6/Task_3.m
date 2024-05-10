clc
clear
close all

num = [1 -1 -4 4];
den = [1 -2.75 1.625 -0.25];
impz(num,den);

[R,P,K] = residuez(num,den);
