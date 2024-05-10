clc
clear
close all

G = linspace(0,12,100);
Z = 0:0.1:0.9;
T = -atan(Z./(sqrt(1-Z.^2)));

for i = 1:length(Z)
    k = sqrt(1-Z(i)^2);
    a = exp(-Z(i)*G);
    b = cos(k.*G+T(i));
    y=1-(a/k).*b;
    h = (a/k).*sin(k*G);
    
    subplot(2,1,1);
    plot(G,y)
    hold on
    grid on
    
    subplot(2,1,2);
    plot(G,h)
    hold on
    grid on
end