clc
clear
close all

s1= tf([100],[1 0 100]); 
p1 = pole(s1); 

s2= tf([100],[1 10 100]);  
p2=pole(s2);
 
s3=tf([100],[1 14 100]); 
p3=pole(s3);
 
s4=tf([100],[1 18 100 ]); 
p4=pole(s4);
 
s5=tf([100],[1 20 100 ]); 
p5=pole(s5);
 
s6=tf([100],[1 30 100]); 
p6=pole(s6);
 
pzmap(s1, s2, s3, s4, s5, s6)
grid on
legend ('s1', 's2', 's3', 's4', 's5', 's6');
