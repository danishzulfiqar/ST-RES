clc
clear
close all

N = 20; 
n = 0:N-1; 
m = 42; 
K = 2; 

x = cos(2*pi*n/N); 

x_time_shifted = x(mod(n-m, N)+1); 

k = 0:N-1; 
x_freq_shifted = exp(-1j*(2*pi*K*m/N))*x 

figure(2)
subplot(2, 1, 1);
stem(n, x, 'b', 'filled'); hold on;
stem(n, x_time_shifted, 'r', 'filled');
xlabel('n');
ylabel('Amplitude');
title('Time-Domain Signals');
legend('Original Signal', 'Time-Shifted Signal');
grid on;

subplot(2, 1, 2);
stem(k, abs(fft(x)), 'b', 'filled'); hold on;
% stem(k, abs(fft(x_freq_shifted)), 'r', 'filled');
xlabel('k');
ylabel('Magnitude');
title('Frequency-Domain Signals');
% legend('Original Signal', 'Frequency-Shifted Signal');
grid on;
