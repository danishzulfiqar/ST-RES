clc
clear
close all

x = [1 7 2 6 9 5]; 

N = length(x);

X = fft(x,N); 
I = zeros(2,3);

% N = 6; 

n1 = 3; 
n2 = 2; 

for i = 1:n2 
for j = 1:n1 
I(i,j) = x(n1*(i-1)+(j-1)+1);
end 
end 
I 

clear i 
ICF = I;
for c = 1:3 
ICF(:,c) = fft(I(:,c),2); 
end 
ICF 

T = zeros(2,3); 
for b = 1:2 
for j = 1:3 
T(b,j) = exp(-i*(2*pi/6))^((b-1)*(j-1));
end 
end 
T; 
B = ICF.*T 

ORF = B; 
for r = 1:2 
ORF(r,:) = fft(B(r,:),3); 
end 
O = ORF; 
O(:); 
[conj(X') O(:)]