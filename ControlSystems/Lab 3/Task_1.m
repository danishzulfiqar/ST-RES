sys = tf([3],[1 4 3]);
t=0:0.1:20;

subplot(4,1,1);
step(sys)
legend('Step Response')

subplot(4,1,2);
sys = tf([3],[1 4 3]);
impulse(sys) 
legend('Impulse Response')

subplot(4,1,3);
ramp=t;
u=ramp*4;
lsim(sys,u,t)
title('Output for Ramp Wave');
legend('Ramp Wave Response');

subplot(4,1,4);
u=sin(t);
lsim(sys,u,t)
title('Output for Sine Wave');
legend('Sine Wave Response');