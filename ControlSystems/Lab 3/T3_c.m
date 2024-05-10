sys=tf([0 6 0],[8 6 1]);
subplot(2,1,1);
step(sys);
legend('Step Response');
subplot(2,1,2);
impulse(sys);
legend('Impulse Response');