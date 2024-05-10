num=[0 0 3];
den=[1 4 3];

sys = tf(num,den);
step(sys, 'r*');

hold on
plot(one, 'b*');
legend("red * (tf graph)", "blue * (simulink graph)");