num = [2 2];
den = conv(conv([1 0 0], [1 2]), [1 5]);

p = rlocus(num, den);
plot(p, '-', 'LineWidth', 2); 
hold on; 
plot(real(p), imag(p), 'rx'); 
plot(0, 0, 'rx'); 
plot(-1, 0, 'go'); 
plot(-2, 0, 'rx'); 
plot(-5, 0, 'rx'); 

numa = 1;
dena = conv(conv([1 2], [1 2]), [1, 2]);

q = rlocus(numa, dena);
plot(q, '.-', 'LineWidth', 2); 

axis([-20 10 -15 15]);
grid on;

syms s k w real;

sys = tf(num, den);
[Num, Den] = tfdata(sys);
sys_ol = poly2sym(cell2mat(Num), s) / poly2sym(cell2mat(Den), s);

sys_ol = k * sys_ol;

sys_cl = sys_ol / (1 + sys_ol);

[Numc, Denc] = numden(sys_cl);

ch_eq = Denc;

s = 1j * w;

res = subs(ch_eq);

E = [real(res) == 0, imag(res) == 0];

S = solve(E, w, k);

w = vpa(S.w);
k = vpa(S.k);

roots = rlocus(num, den, k(2));
