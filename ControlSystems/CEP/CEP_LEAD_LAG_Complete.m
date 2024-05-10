s = tf('s');
T = (s+3)/(s*(s+1)*(s+2)*(s+4))
Kle = 3.1*((s+1.5)/(s+4));
kla = (s+0.00258)/(s+0.0003);
sys_cl = feedback(Kle*kla*T,1);
figure()
step(sys_cl)
set(findall(gca,'type','line'), 'markersize', 8, 'linewidth', 2);
figure()
rlocus(Kle*kla*T/3.1)
set(findall(gca,'type','line'), 'markersize', 8, 'linewidth', 2);