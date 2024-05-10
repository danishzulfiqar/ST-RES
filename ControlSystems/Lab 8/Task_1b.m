clc
clear
close all

s = tf('s'); 
t = 0:0.01:10; 
G = (500*(s+2)*(s+5)*(s+6))/(s*(s+8)*(s+10)*(s+12));
T = feedback(G,1);
E = 1-T;
 
subplot(3,1,1);
kp = dcgain(G);
E_step = 1/(1+kp);
step (T,t), grid on;  
xlabel('Time');
ylabel('Amplitude');
title('Step Response');

subplot(3,1,2);
u = heaviside(t);
ramp = 20.*t.*u; 
kv = dcgain(s.*G);
E_ramp = 20/kv;
lsim(T,ramp,t), grid on;
xlabel('Time');
ylabel('Amplitude');
title('Ramp Response');
 
subplot(3,1,3);
parabola = 20.*(t.^2).*u; 
ka = dcgain((s^2).*G);
E_parabola = 5/ka;
lsim(T,parabola,t), grid on;
xlabel('Time');
ylabel('Amplitude');
title('Parabolic Response');
