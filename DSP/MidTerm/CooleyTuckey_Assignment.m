clc
clear
close all

% x = rand(1,15);
x = [1 7 2 6 9 5 2 4 7 3 2 4 7 11 3];
X = fft(x,15);
I = zeros(3,5);

N = 15
n1 = 5;
n2 = 3;

for i = 1:n2
 for j = 1:n1
 I(i,j) = x(n1*(i-1)+(j-1)+1);
 end
end
I

clear i
ICF = I;
for c = 1:5
 ICF(:,c) = fft(I(:,c),3);
end
ICF

T = zeros(3,5);
for b = 1:3
 for j = 1:5
 T(b,j) = exp(-i*(2*pi/15))^((b-1)*(j-1));
 end
end
T;
B = ICF.*T

ORF = B;
for r = 1:3
 ORF(r,:) = fft(B(r,:),5);
end
O = ORF;
O(:);

[conj(X') O(:)]