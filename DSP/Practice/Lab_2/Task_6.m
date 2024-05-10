clc
clear
close all

n = -10:10;

u = @(n) double(n>=0);

u_val = u(n);

signal = u(n)+u(n+1);

stem(n,signal);