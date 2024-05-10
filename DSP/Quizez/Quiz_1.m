sys = tf(1,[1 6 18]);
% pause;
figure(1)
bode(sys)
% pause;
[mag_b,ph_b] = bode(sys,7)
% pause;
t = linspace(0,10*(2*pi/7),5000);
y = sin(7*t);
figure(2)
plot(t,y)
hold on
plot(t,zeros(length(t)),'r.')
hold off
% pause;
figure(3)
lsim(sys,y,t)
% pause;
sprintf('0.019*sin(7t-126.4)')
% pause;
Y = lsim(sys,y,t);
figure(4)
plot(t,Y)
hold on
yc = 0.019*sin(7*t-deg2rad(126.4));
plot(t,yc,'r.')
hold off
% pause;
clc
syms s
syms w real
sys = 1/(s^2+6*s+18)
% pause;
s = w*1i
% pause;
sys_f = subs(sys,s)
% pause;
sys_mag = abs(sys_f)
% pause;
sys_ph = angle(sys_f)
% pause;
w = 7
% pause;
mag = vpa(subs(sys_mag,w))
% pause;
ph = vpa(rad2deg(vpa(subs(sys_ph,w))))
% pause;