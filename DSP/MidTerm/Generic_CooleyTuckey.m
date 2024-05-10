clc
clear
close all

x = rand(1,15);

% x = [1 0 1 0 1 0]; 

N = length(x);

f = factor(N);

% n1 = 5; 
% n2 = 3; 

n1 = f(2); 
n2 = f(1); 

disp("n1: " + n1);
disp("n2: " + n2);

X = fft(x,N); 
I = zeros(n2,n1);

for i = 1:n2 
for j = 1:n1 
I(i,j) = x(n1*(i-1)+(j-1)+1);
end 
end 
I 

clear i 
ICF = I;
for c = 1:n1 
ICF(:,c) = fft(I(:,c),n2); 
end 
ICF 

T = zeros(n2,n1); 
for b = 1:n2 
for j = 1:n1 
T(b,j) = exp(-i*(2*pi/N))^((b-1)*(j-1));
end 
end 
T; 
B = ICF.*T 

ORF = B; 
for r = 1:n2 
ORF(r,:) = fft(B(r,:),n1); 
end 
O = ORF; 
O(:); 
[conj(X') O(:)]


