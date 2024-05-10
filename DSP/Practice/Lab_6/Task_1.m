clc
clear
close all

num = [18 0 0 0];
den = [18 3 -4 -1];

roots(num); 
roots(den);

zplane(num,den); 
[R,P,K] = residuez(num,den);
