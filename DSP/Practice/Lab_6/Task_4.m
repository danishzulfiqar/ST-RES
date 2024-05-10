clc
clear
close all

num = [1 1];
den = [1 -0.9 0.81];
w = [0:1:500]*pi/500;

H=freqz(num,den,w);
magH = abs(H);
phaH = angle(H)*180/pi;

subplot(2,1,1);
plot(w/pi,magH,'b','LineWidth',3);
title('Magnitude Response');
xlabel('Frequency ');
ylabel('Magnitude of H');

subplot(2,1,2);
plot(w/pi,phaH,'r','LineWidth',3);
title('Phasor Response');
xlabel('Frequency');
ylabel('Degrees');