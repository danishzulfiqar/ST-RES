s = tf('s');
T = (s+3)/(s*(s+1)*(s+2)*(s+3))
K = 2.5*((s+1.5)/(s+4))
sys_cl = feedback(K*T,1);
figure()
step(sys_cl)
figure()
rlocus(K*T/2.5)