clc;
clear;
close all;

t=-10:0.01:10;
T=4; fm=1/T;
x=cos(2*pi*fm*t);
subplot(2,2,1);  
plot(t,x); 
title('msg signal'); 
xlabel('time'); 
ylabel('amplitude'); 
fs1=1.6*fm; 
fs2=2*fm;
fs3=8*fm; 
n1=-4:1:4; 
x1=cos(2*pi*fm/fs1*n1);
subplot(2,2,2);
stem(n1,x1); 
hold on; 
subplot(2,2,2); 
plot(n1,x1,'r'); 
title('sampling when fs<2fm'); 
xlabel('sample'); 
ylabel('amplitude');
n2=-5:1:5; 
x2=cos(2*pi*fm/fs2*n2); 
subplot(2,2,3); 
stem(n2,x2); 
hold on; 
subplot(2,2,3);
plot(n2,x2,'r');
title('sampling when fs=2fm'); 
xlabel('sample');
ylabel('amplitude'); 
n3=-20:1:20; 
x3=cos(2*pi*fm/fs3*n3); 
subplot(2,2,4); 
stem(n3,x3);
hold on; subplot(2,2,4);
plot(n3,x3,'r');
title('sampling when fs>2fm'); 
xlabel('sample');
ylabel('amplitude');