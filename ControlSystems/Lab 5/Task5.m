clc
clear
close all

z=0:0.01:1; 
PO=100*exp((-z.*pi)./(1-z.^2).^0.5); 
plot(z,PO,'linewidth',2), grid on;
title('%OS vs Damping ratio');
xlabel('Damping ratio');
ylabel('Percentage overshoot');
stepinfo(PO )