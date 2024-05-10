clc
clear
close all

% Function to generate continuous-time signal
function x = generate_continuous_signal(t, fm)
    x = cos(2*pi*fm*t);
end

% Function to sample the continuous-time signal
function [n, xn] = sample_signal(t, x, fs)
    Ts = 1/fs;
    n = 0:ceil((max(t)-min(t))/Ts);
    xn = x(n*Ts + min(t));
end


t = -100:0.01:100;
T = 30;
fm = 1/T;

x = generate_continuous_signal(t, fm);

subplot(2,2,1);
plot(t,x);
grid on;
xlabel('Time in seconds');
ylabel('x(t)');
title('Continuous time signal');

% Define sampling frequencies
sampling_frequencies = [1.6, 2, 8] * fm;

for i = 1:length(sampling_frequencies)
    fs = sampling_frequencies(i);
    [n, xn] = sample_signal(t, x, fs);

    subplot(2,2,i+1);
    stem(n,xn);
    hold on;
    plot(n, xn);
    grid on;
    xlabel('Time in seconds');
    ylabel('x[n]');
    title(['Discrete time signal with fs = ', num2str(fs)]);
end
