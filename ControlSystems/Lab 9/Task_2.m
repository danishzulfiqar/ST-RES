clc
clear
close all

s = tf('s');
P = 1/(s^2 + 10*s + 20);
step(P);

Kp1 = 400;
Kd1 = 5;
Kp2 = 400;
Kd2 = 15;
Kp3 = 400;
Kd3 = 25;

C1 = pid(Kp1,0,Kd1);
T1 = feedback(C1*P,1)
t = 0:0.01:2;
C2 = pid(Kp2,0,Kd2);
T2 = feedback(C2*P,1)
C3 = pid(Kp3,0,Kd3);
T3 = feedback(C3*P,1)

step(P);

hold on;
grid on;

step(T1,t);
step(T2,t);
step(T3,t);

legend('step input','Kd=5','Kd=15','Kd=25')
