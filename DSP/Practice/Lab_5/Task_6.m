% duality property of DFT 
clc
clear
close all

x1=[4 -1 2 -3 5];
x2=[7 8 -6 0 6];
[y,N] = circonv(x1,x2);

LHS=fft(y);
w=linspace(-pi,pi,N);

subplot(2,1,1),stem(w,abs(LHS),'linewidth',2),
xlabel('w'),ylabel('Amplitude'),title('LHS');
X1=fft(x1);
X2=fft(x2);

RHS=X1.*X2;

subplot(2,1,2),stem(w,abs(RHS),'linewidth',2),
xlabel('w'),ylabel('Amplitude'),title('RHS');