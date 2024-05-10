% clc
% clear
% close all

s = tf("s");

sys = (s+3)/(s*(s+1)*(s+2)*(s+4))
sisotool(sys_lead)
