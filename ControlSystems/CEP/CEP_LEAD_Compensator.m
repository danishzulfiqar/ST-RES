s = tf('s');
T = (s+3)/(s*(s+1)*(s+2)*(s+4))
Kle = 3.2*((s+1.5)/(s+4));
sys_cl = feedback(Kle*T,1);
figure(1);
rlocus(Kle*T/3.2)
set(findall(gca,'type','line'), 'markersize', 8, 'linewidth', 2);
figure(2);
step(sys_cl)
set(findall(gca,'type','line'), 'markersize', 8, 'linewidth', 2);