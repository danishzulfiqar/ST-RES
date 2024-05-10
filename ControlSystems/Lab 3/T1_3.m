sys = tf([3],[1 4 3]);
t=0:0.1:20;
ramp=t;
u=ramp*4;
lsim(sys,u,t)
title('Output for Ramp Wave');
legend('Ramp Wave Response');