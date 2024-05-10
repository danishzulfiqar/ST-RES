clc
clear
close all

t_continuous = 0:0.001:10; 
x_continuous = cos(t_continuous); 

sampling_rate = 5; 
t_sampled = 0:1/sampling_rate:10; 
x_sampled = cos(t_sampled);


figure;
subplot(2,1,1);
plot(t_continuous, x_continuous);
title('Continuous Signal');
xlabel('Time');
ylabel('Amplitude');

subplot(2,1,2);
stem(t_sampled, x_sampled);
title('Sampled Signal');
xlabel('Time');
ylabel('Amplitude');
