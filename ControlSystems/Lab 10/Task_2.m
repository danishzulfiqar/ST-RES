clc
clear
close all

s= tf('s')
open_lp=1/(s*(s+3)*(s+4)*(s+8)) 
close_loop= feedback(open_lp,1) 
rlocus(close_loop) 
axis([-2 1 -2 5])