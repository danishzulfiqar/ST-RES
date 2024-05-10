% ANALYTICAL SOLUTION
ch_eq = [1, 12, 86, 300, 625];
s = roots(ch_eq);
A = [1, 1, 1, 1; s(1), s(2), s(3), s(4); s(1)^2, s(2)^2, s(3)^2, s(4)^2; s(1)^3, s(2)^3, s(3)^3, s(4)^3];
X = [0, 0, 0, 768]';
Y = A\X;
t = linspace(0, 3.5, 100);
y = Y(1)*exp(s(1)*t) + Y(2)*exp(s(2)*t) + Y(3)*exp(s(3)*t) + Y(4)*exp(s(4)*t);
y = real(y);

% Create Figure 1
figure(1);

% Subplot 1: Analytical Solution
subplot(2,1,1);
plot(t, y, 'r')
grid on
title('Analytical Solution')
xlabel('Time (s)')
ylabel('Amplitude')

% MATLAB IMPULSE COMMAND
num = 768;
den = ch_eq;
sys = tf(num, den);
h_m = impulse(sys, t);

% Subplot 2: MATLAB Impulse Response
subplot(2,1,2);
plot(t, h_m, 'k');
grid on
title('MATLAB Impulse Response')
xlabel('Time (s)')
ylabel('Amplitude')

% LAPLACE DOMAIN PARTIAL FRACTIONS
[r, p, k] = residue(num, den);
syms x;
H = r(2)/((x-p(2))^2) + r(4)/((x-p(4))^2) + r(1)/(x-p(1)) + r(3)/(x-p(3));
h = ilaplace(H);
h = subs(real(h));

% Create Figure 2
figure(2);

% Subplot 1: Laplace Domain Solution
subplot(2,1,1);
plot(t, h, 'b');
grid on
title('Laplace Domain Solution')
xlabel('Time (s)')
ylabel('Amplitude')

% SUPERIMPOSED GRAPH
subplot(2,1,2);
plot(t, h_m, 'g', 'LineWidth', 3)
hold on
plot(t, y, 's', 'LineWidth', 1)
plot(t, h, 'b.', 'LineWidth', 0.5)
legend('IMPULSE', 'ANALYTICAL', 'LAPLACE')
grid on
title('Superimposed Graph')
xlabel('Time (s)')
ylabel('Amplitude')

% POLE ZERO PLOT
figure(3);
pzmap(sys);
grid on
title('Pole-Zero Plot')
