% clc
% clear
% close all

z=[-0.01 -6];
p=[0 -20 -100];

k=11017.01;
K=zpk(z,p,k);
G=tf([10],[1 10 29]);

t=0:0.01:10;
x=ones(1,length(t));
y=lsim((K.*G)/(1+K.*G),x,t);

plot(t,y)

title('Output for Pre Lab part a')
xlabel('time(s)')
ylabel('Amplitude')