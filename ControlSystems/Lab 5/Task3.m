clc
clear
close all

t =0:0.01:3;
u=ones(size(t));
l1=tf([100],[1 0 100]); 
l2=tf([100],[1 10 100]);  
l3=tf([100],[1 14 100]); 
l4=tf([100],[1 18 100]); 
l5=tf([100],[1 20 100]); 
l6=tf([100],[1 30 100]);
 
[y1,t]=lsim(l1,u,t);
plot(t,y1,'linewidth',3), grid on;
title('Step response of second order system for different value of \zeta');
xlabel('Time');
ylabel('Amplitude');

[y2,t]=lsim(l2,u,t);
[y3,t]=lsim(l3,u,t);
[y4,t]=lsim(l4,u,t);
[y5,t]=lsim(l5,u,t);
[y6,t]=lsim(l6,u,t);
hold on; grid on;

plot(t,y2,'r --','linewidth',3);
plot(t,y3,'.','linewidth',3);
plot(t,y4,'-.','linewidth',3);
plot(t,y5,':','linewidth',3);
plot(t,y6,'-o');
legend('\zeta=0','\zeta=0.5','\zeta=0.7','\zeta=0.9','\zeta=1','\zeta=1.5');

% stepinfo(l1);
% stepinfo(l2);
% stepinfo(l3);
% stepinfo(l4);
% stepinfo(l5);
% stepinfo(l6);