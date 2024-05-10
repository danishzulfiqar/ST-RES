syms s;
G1=tf([1],[1 6]);
G2=tf([1],[1 9]);
G3=tf([1],[1 11]);

G1.InputName = 'R'
G1.OutputName = 'X1'
G2.InputName = 'R'
G2.OutputName = 'X2'
G3.InputName = 'R'
G3.OutputName = 'X3'

sys = parallel(parallel(G1,G2),G3);
[y t] = step(sys);
plot(t,y,'linewidth',2), grid on

title('Step Response')
xlabel('t')
ylabel('u(t)')