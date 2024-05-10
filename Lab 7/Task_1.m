D=[1 2 9];

G1=tf([9],D);
step(G1,'b') 

G2=tf([9 27],[3*D]);
hold on; 

step(G2,'r')
G3=tf([9 45],[5*D]);

hold on;
step(G3,'g');
G4=tf([9 90],[10*D]);

hold on;
step(G4,'black')

figure()
subplot(2,1,1)
pzmap(G1);
grid on;
legend('G1') 

subplot(2,1,2)
pzmap(G2);
grid on;
legend('G2')
figure()

subplot(2,1,1);
pzmap(G3);
grid on;

legend('G3')
subplot(2,1,2);
pzmap(G4);
grid on
legend('G4')