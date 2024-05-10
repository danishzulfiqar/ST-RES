clc
clear
close all

x=[1 2 4 6 8 10 12 16]
n=[0: length(x)-1]

factor=input('samping by factor:')
x_downsampled=[ ]
for i=1:factor:length(x)
    x_downsampled=[x_downsampled x(i)]
end
grid on
subplot 211
stem(n, x)
xlabel('n')
ylabel('value')
title('origional signal')
grid on

subplot 212
stem(0:length(x_downsampled)-1,x_downsampled, Color="red", LineWidth=1)
xlabel('n')
ylabel('v')
title('down sampled signal signal')
grid on



