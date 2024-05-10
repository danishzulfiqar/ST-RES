s = tf('s');
sys_ol = (s+3)/(s*(s+1)*(s+2)*(s+4));
figure(1);
rlocus(sys_ol);
title('Open Loop Root Locus');
axis([-4.5 1 -3 3])
set(findall(gca,'type','line'), 'markersize', 15, 'linewidth', 4);
grid on;