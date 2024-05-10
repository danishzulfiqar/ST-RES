clc
clear
close all

s = tf('s');
P = 1/(s^2 + 10*s + 20)

Kp = 400;
Ki = 550;
Kd = 45;

C = pid(Kp,Ki,Kd);

T = feedback(C*P,1)

t = 0:0.001:10;

[y1,t] = step(P), grid on;
step(t,T);
