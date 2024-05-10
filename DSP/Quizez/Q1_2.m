syms s
syms w real
sys = 1/(s^2+14*s+98)
s = w*1i
sys_f = subs(sys,s)
sys_mag = abs(sys_f)
sys_ph = angle(sys_f)
w = 1
mag = vpa(subs(sys_mag,w))
ph = vpa(rad2deg(vpa(subs(sys_ph,w))))
