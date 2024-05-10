% Define the range of values for the sequence
n = -10:10;

% Initialize the signal vector
piecewise_signal = zeros(size(n));

% Define the conditions for each piece
condition_1 = (n >= -10) & (n < 0);
condition_2 = (n >= 0) & (n <= 5);
condition_3 = (n > 5) & (n <= 10);

% Define the values for each piece
piecewise_signal(condition_1) = 0;
piecewise_signal(condition_2) = n(condition_2);
piecewise_signal(condition_3) = 10 - n(condition_3);

% Plot the piecewise signal
stem(n, piecewise_signal, 'filled');
xlabel('n');
ylabel('Amplitude');
title('Piecewise Signal');
grid on;
