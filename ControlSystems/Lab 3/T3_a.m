sys=tf([3],[24 4 3]);
subplot(2,1,1);
step(sys);
legend('Step Response');
subplot(2,1,2);
impulse(sys);
legend('Impulse Response');