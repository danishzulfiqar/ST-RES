% Define the range of 'n'
n = -10:10;

% Define the unit step function u[n]
u = @(n) double(n >= 0);

% Compute u[n] - u[n-1]
x = u(n) + u(n + 1);

% Plot the sequence
stem(n, x, LineWidth=1);
xlabel('n');
ylabel('x[n]');
title('Plot of u[n] - u[n-1]');
grid on;
