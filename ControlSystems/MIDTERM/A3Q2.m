num = [1 0.6667];
den = [1 3.3401 7.0325 0 0];

p = rlocus(num, den);
plot(p, '-');

hold on;
plot(p, 'rx');
plot(0, 0, 'rx');
plot(-0.6667, 0, 'go');
plot(-1.6701, 2.06, 'rx');
plot(-1.6701, -2.06, 'rx');

numa = 1;
dena = [1 4.0068 5.3515 2.3825];

q = rlocus(numa, dena);
plot(q, '-.');
axis([-12 6 -10 10]);
grid on;
