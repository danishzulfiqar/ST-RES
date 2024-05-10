% clc
% close all
% clear 

syms s;
f = ((s^5)+(8*s^4)+(23*s^2)+(28*s)+3)/((s^3)+(6*s^2)+(8*s));

y = ilaplace(f);
pretty(y);

[r,p,k]=residue([1 8 23 35 28 3],[1 6 8 0]);
x = laplace(y);
pretty(x);