% clc
% close all
% clear

[z,p,k]=tf2zp([1 0.25],[1 6 11 6 0]); 
zero=[-0.25]; 
poles=[0 -1 -2 -3]; 
gain=1;

[num,denom]=zp2tf(zero,poles,gain);  
syms s; 
f=(s+0.25)/(s*(s+1)*(s+2)*(s+3));
g=ilaplace(f);
pretty(g)

h=laplace(g);
pretty(h)       