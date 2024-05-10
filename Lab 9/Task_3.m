clc
clear
close all

s = tf('s');
P = 1/(s^2 + 10*s + 20);

Kp = 40;
Ki1 = 60;
Ki2 = 75;
Ki3 = 90;

C1 = pid(Kp,Ki1);
T1 = feedback(C1*P,1)
t = 0:0.01:2;
C2 = pid(Kp,Ki2);
T2 = feedback(C2*P,1)
C3 = pid(Kp,Ki3);
T3 = feedback(C3*P,1)

step(P);

hold on;
grid on;

step(T1,t)
step(T2,t)
step(T3,t)

legend('step input','Ki=60','Ki=70','Ki=80')
