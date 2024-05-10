syms s

G_s = (s + 3) / (s * (s + 1) * (s + 2) * (s + 4));

D = 1; 

D_s = D / s;

E_s = D_s / (1 + G_s);

e_ss = limit(s * E_s, s, 0);

disp('The steady-state error e_ss is:');
disp(vpa(e_ss, 6)); 
