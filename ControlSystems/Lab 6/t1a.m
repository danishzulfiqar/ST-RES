lsyms s;
G1=tf([1],[1 6]);
G2=tf([1],[1 9]);
G3=tf([1],[1 11]);

G1.InputName = 'R';
G1.OutputName= 'X2';
G2.InputName = 'X2';
G2.OutputName= 'X1';
G3.InputName = 'X1';
G3.OutputName= 'C';

sys = series(series(G1,G2),G3)
t = linspace(0,2,100)
[y,t] =step(sys,t)

plot(t,y,'linewidth',2),grid on
title('step response')
xlabel('t');
ylabel('u(t)');