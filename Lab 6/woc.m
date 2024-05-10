clc
clear all
close all
plant=tf([0 0 1],[1 6 0]);
plant.outputname='Y';plant.inputname='u';
sum=sumblk('u','Y','R','-+')
T=connect(plant,sum,'R','Y');
step(T)