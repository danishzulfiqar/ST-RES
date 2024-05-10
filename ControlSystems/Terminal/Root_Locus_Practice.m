clc
clear
close all

s = tf("s");

sys = 1 / (s*(s+2)*(s+4));


% rlocus(sys), grid on

% sisotool(sys)

pidtune(sys, 'pid')

