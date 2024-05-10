clc
close all
clear all
k=0.01;
T=[0 0 0 154980];
B=[1 170 4625 165480];
G=tf(T,B)
t=0:0.1:2;
x=ones(1,length(t));
O=lsim(G,x,t);
plot(t,O);
title('Output for Pre Lab part c')
xlabel('time(s)')
ylabel('Amplitude')