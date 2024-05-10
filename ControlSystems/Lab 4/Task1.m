clc
clear
close all

syms s

num = [1];
den = [1, 1, 3, 1, 1];

[r, p, k] = residue(num, den);

nr = conv([1, -p(1)], [1, -p(2)]);
ns = poly2sym(nr, s);
dr = conv([1, -p(3)], [1, -p(4)]);
ds = poly2sym(dr, s);

nlo = (0.13*1i)*(s - p(2)) + (-0.13*1i)*(s - p(1));
nlt = (-0.06*1i)*(s - p(4)) + (0.06*1i)*(s - p(3));

H = nlo/ns + nlt/ds;

h = ilaplace(H);

t = linspace(0, 120, 1000);

h = double(subs(h));

one = 2*0.13*exp(-1.3*t).*cos(0.46*t + deg2rad(90));
two = 2*0.06*exp(-0.05*t).*cos(1.04*t - deg2rad(90));
y = one + two;

figure(1)
subplot(2,1,1);
plot(t, y, 'r')
title('Time Response')
xlabel('Time (s)')
ylabel('Amplitude')
grid on

subplot(2,1,2);
plot(t, h, 'b')
title('h(t) Response')
xlabel('Time (s)')
ylabel('Amplitude')
grid on

figure(2)
subplot(2,1,1);
sys = tf(num, den);
impulse(sys, 'k')
title('Impulse Response')
grid on

subplot(2,1,2);
plot(t, y, 'r*')
hold on
plot(t, h, 'b-')
title('Overlay of Time Response and h(t)')
xlabel('Time (s)')
ylabel('Amplitude')
grid on
