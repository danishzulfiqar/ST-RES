clc
clear
close all

s = tf('s');
P = 1/(s^2 + 10*s + 20);

Kp1 = 200;
Kp2 = 250;
Kp3 = 400;

C1 = pid(Kp1)
T1 = feedback(C1*P,1)
t = 0:0.01:2;
C2 = pid(Kp2)
T2 = feedback(C2*P,1)
C3 = pid(Kp3)
T3 = feedback(C3*P,1)

step(P);
hold on;
grid on;

step(T1,t)
step(T2,t)
step(T3,t)

legend('step input','Kp=200','Kp=250','Kp=400')
hold off
