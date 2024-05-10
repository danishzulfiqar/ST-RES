sys = tf([3],[1 4 3]);
t=0:0.1:20;
u=sin(t);
lsim(sys,u,t)
title('Output for Sine Wave');
legend('Sine Wave Response');