syms s
G1=tf([1],[1 1]);
G2=tf([1],[1 2]);
G3=tf([1],[1 3]);
G4=tf([1],[1 4]);
G5=tf([1],[1 5]);
G6=tf([1],[1 6]);
G7=tf([1],[1 7]);
G8=tf(1,[1 8]);
G1.InputName = 'X1';
G1.OutputName = 'X2';
G2.InputName = 'X5';
G2.OutputName = 'X3';
G3.InputName = 'X5';
G3.OutputName = 'X6';
G4.InputName = 'X5';
G4.OutputName = 'X7';
G5.InputName = 'X10';
G5.OutputName = 'X13';
G6.InputName = 'C';
G6.OutputName = 'X12';
G7.InputName = 'X10';
G7.OutputName = 'C';
G8.InputName = 'C';
G8.OutputName = 'X8';
sum1 = sumblk('X1','R','A','+-');
sum2 = sumblk('X5','X2','X8','++');
sum3 = sumblk('B','X6','X7','++');
sum4 = sumblk('X10','X12','B','-+');
sum5 = sumblk('A','X13','X3','++');
Output =connect(G1,G2,G3,G4,G5,G6,G7,G8,sum1,sum2,sum3,sum4,sum5,'R','C');
step(Output), grid on
hold on
plot(task2btes1)