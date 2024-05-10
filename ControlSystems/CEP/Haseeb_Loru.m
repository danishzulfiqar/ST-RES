s=tf('s')
T=(s+3)/(s*(s+1)*(s+2)*(s+4))
k_led = 2.45*(s+1.2/((s+2.43)))
sys_cl = feedback(k_led*T,1);
figure(1);
rlocus(k_led*T/2.45)
