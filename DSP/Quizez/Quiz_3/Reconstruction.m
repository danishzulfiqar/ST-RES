clc
clear
close all

% Parameters
wo = 2000*pi;  % Angular frequency
ws = pi/2;     % Sampling interval (given as omega_s)


t_continuous = linspace(0, 10, 1000); 

x_continuous = cos(wo * t_continuous);

n_samples = 100;  

n = 0:(n_samples - 1);  
t_sampled = n * ws;  
x_sampled = cos(wo * t_sampled);

t_reconstructed = linspace(0, 10, 1000);  
x_reconstructed = zeros(size(t_reconstructed));

for n = 1:n_samples
    x_reconstructed = x_reconstructed + x_sampled(n) * sinc((t_reconstructed - n*ws) / ws);
end

% Plot
figure;
subplot(3,1,1);
plot(t_continuous, x_continuous, 'b', 'LineWidth', 2);
title('Continuous Signal x(t)');
xlabel('Time (t)');
ylabel('Amplitude');

subplot(3,1,2);
stem(t_sampled, x_sampled, 'r', 'Marker', 'o');
title('Sampled Signal x(nTs)');
xlabel('Time (t)');
ylabel('Amplitude');

subplot(3,1,3);
plot(t_reconstructed, x_reconstructed, 'g', 'LineWidth', 2);
title('Reconstructed Signal x_r(t)');
xlabel('Time (t)');
ylabel('Amplitude');

% Adjust subplot spacing
sgtitle('Signal Reconstruction');

