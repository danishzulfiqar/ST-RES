clc
clear
close all

s = tf("s");
sys = (s+3)/(s*(s+1)*(s+2)*(s+4));

% roots of (4*s^3 + 21*s^2 +28*s + 8 + k) 

roots([4 21 28 8])
