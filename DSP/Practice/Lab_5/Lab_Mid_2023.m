clc
clear
close all

% Generate a discrete-time signal x[n] (e.g., a cosine wave)
N = 64;  % Period of the signal
n = 0:N-1;
x_n = cos(2 * pi * n / N);  % Example signal (cosine wave)

% Compute the DFT of x[n]
X_k = fft(x_n);

% Compute the inverse DFT of X[k] (using the duality property)
X_n = ifft(N * conj(X_k));

% Plot the original signal and its DFT
figure;
subplot(2, 2, 1);
stem(n, x_n, 'r', 'filled');
title('Original Signal x[n]');
xlabel('n');
ylabel('x[n]');

subplot(2, 2, 2);
stem(0:N-1, abs(X_k), 'b', 'filled');
title('Magnitude of DFT X[k]');
xlabel('k');
ylabel('|X[k]|');

% Plot the inverse DFT of X[k]
subplot(2, 2, 3);
stem(n, real(X_n), 'g', 'filled');
title('Inverse DFT of X[k] (Real part)');
xlabel('n');
ylabel('X[n]');

subplot(2, 2, 4);
stem(n, imag(X_n), 'm', 'filled');
title('Inverse DFT of X[k] (Imaginary part)');
xlabel('n');
ylabel('X[n]');

sgtitle('Duality Property of DFT');
