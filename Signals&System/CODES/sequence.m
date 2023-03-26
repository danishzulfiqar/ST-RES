function [ ] = sequence(x,n,n0,a,b)
subplot(5,1,1);
stem(n,x,'LineWidth',2);
grid on
legend ('x[n]');

subplot(5,1,2);
stem(n+n0, x,'LineWidth', 2);
grid on
legend('x[n-n0]')

subplot(5,1,3);
stem(-n , x,'LineWidth', 2);
grid on
legend('x[-n]')

x1=downsample(x,a); 
n1=n(1:a:end);
subplot(5,1,4);
stem(n1,x1,'LineWidth',2); 
grid on
legend('x[an])'); 

x2=upsample(x,b); 
i=(length(x2)-1)/2; 
n2=-i:i; 
subplot(5,1,5); 
stem(n2,x2,'LineWidth',2); 
grid on
legend('x[bn]');
