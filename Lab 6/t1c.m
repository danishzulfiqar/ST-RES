syms s;
% transfer functions
G1=tf([1],[1 6]);
G2=tf([1],[1 9]);
G3=tf([1],[1 11]);
H1 = tf(1,[1 4]);
H2 = tf(1,[1 2]);
G1.InputName = 'R'
G1.OutputName = 'S'
G2.InputName = 'E'
G2.OutputName = 'X1'
G3.InputName = 'X2'
G3.OutputName = 'X3'
H2.InputName = 'X2'
H2.OutputName = 'X3'
H1.InputName = 'X3'
H1.OutputName = 'Y'
sys1 = series(G2,G3)
sys2 = series(H1,H2)
fd = feedback(sys1,sys2,+1)
output = fd * G1
step(output), grid on