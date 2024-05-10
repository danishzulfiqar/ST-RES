s = tf('s');
T = (s+3)/(s*(s+1)*(s+2)*(s+4))

figure()
rlocus(T)
title('Root Locus befor Compensator');
set(findall(gca,'type','line'), 'markersize', 8, 'linewidth', 2);
axis([-4.5 1 -3 3])
grid on;

figure()
sys_cl = feedback(T,1);
step(sys_cl)

set(findall(gca,'type','line'), 'markersize', 8, 'linewidth', 2);