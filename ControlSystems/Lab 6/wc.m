clc
clear all
close all
plant=tf([0 0 1],[1 6 0]);
controller=tf([18],[1]);
plant.outputname='Y';plant.inputname='u';
controller.outputname='u';controller.inputname='e';
sum=sumblk('e','Y','R','-+')
T=connect(plant,controller,sum,'R','Y');
step(T)