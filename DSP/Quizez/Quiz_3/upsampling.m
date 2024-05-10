clc
clear
close all

x=[1 2 3 4 5]
n=[0: length(x)-1]

factor=input('samping by factor:')
x_upsampled=[ ] 
for i=1:length(x)
    x_upsampled=[x_upsampled x(i)]
    for j=1:factor-1
       x_upsampled=[x_upsampled 0] 
    end
end

subplot 211
stem(n, x)
xlabel('n')
ylabel('value')
title('origional signal')

subplot 212
stem(0:length(x_upsampled)-1,x_upsampled)
xlabel('n')
ylabel('v')
title('upsampled signal')
