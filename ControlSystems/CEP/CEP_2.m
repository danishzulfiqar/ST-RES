s = tf('s');
T = (s+3)/(s*(s+1)*(s+2)*(s+3))
Kle = 2.5*((s+1.5)/(s+4));
kla = (s+0.000106)/(s+0.00001);
sys_cl = feedback(Kle*kla*T,1);
figure()
step(sys_cl)
figure()
rlocus(Kle*kla*T/2.5)