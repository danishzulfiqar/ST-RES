clc
clear
close all

x = randn(1, 100);

% display("Sum: " + sum(x));
% display("Total Elements: " + length(x));

y = running_average(x);

display("cumsum: " + y);

subplot(2,1,1);
plot(x);
title('Input Signal');
xlabel('Sample');
ylabel('Amplitude');
grid on;

subplot(2,1,2);
plot(y);
title('Running Total');
xlabel('Sample');
ylabel('Running Total');
grid on;
