clc
clear
close all

% Define symbolic variable s
syms s

% Define numerator and denominator coefficients
num = [6, 2];
den = [20, 54, 65, 60, 41];

% Calculate partial fraction decomposition
[r, p, k] = residue(num, den);

% Compute numerator and denominator polynomials
nr = conv([1, -p(1)], [1, -p(2)]);
ns = poly2sym(nr, s);
dr = conv([1, -p(3)], [1, -p(4)]);
ds = poly2sym(dr, s);

% Define transfer functions nlo and nlt
nlo = (0.13*1i)*(s - p(2)) + (-0.13*1i)*(s - p(1));
nlt = (-0.06*1i)*(s - p(4)) + (0.06*1i)*(s - p(3));

% Compute the overall transfer function H
H = nlo/ns + nlt/ds;

% Inverse Laplace transform to get the time domain response h(t)
h = ilaplace(H);

% Define the time vector
t = linspace(0, 120, 1000);

% Evaluate and convert h to double
h = double(subs(h));

% Calculate two components of the output
one = 2*0.13*exp(-1.3*t).*cos(0.46*t + deg2rad(90));
two = 2*0.06*exp(-0.05*t).*cos(1.04*t - deg2rad(90));
y = one + two;

% Plot the time response
figure(1)
subplot(2,1,1);
plot(t, y, 'r')
title('Time Response')
xlabel('Time (s)')
ylabel('Amplitude')
grid on

% Plot h(t)
subplot(2,1,2);
plot(t, h, 'b')
title('h(t) Response')
xlabel('Time (s)')
ylabel('Amplitude')
grid on

% Create a transfer function model and plot its impulse response
figure(2)
subplot(2,1,1);
sys = tf(num, den);
impulse(sys, 'k')
title('Impulse Response')
grid on

% Overlay the time response and h(t)
subplot(2,1,2);
plot(t, y, 'r*')
hold on
plot(t, h, 'b-')
title('Overlay of Time Response and h(t)')
xlabel('Time (s)')
ylabel('Amplitude')
grid on

% Plot the pole-zero map of the transfer function
figure(5)
pzmap(sys)
title('Pole-Zero Map')

% Adjust marker size for poles and zeros
hm = findobj(gca, 'Type', 'Line');
hm(2).MarkerSize = 20;
hm(3).MarkerSize = 20;
