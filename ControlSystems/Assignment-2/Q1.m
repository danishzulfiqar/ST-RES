wnt = linspace(0,12,100);
zeta = 0:0.1:0.9;
theta = -atan(zeta./(sqrt(1-zeta.^2)));
for i = 1:length(zeta)
k = sqrt(1-zeta(i)^2);
a = exp(-zeta(i)*wnt);
b = cos(k.*wnt+theta(i));
y=1-(a/k).*b;
h = (a/k).*sin(k*wnt);
figure(1)
plot(wnt,y)
hold on
grid on
figure(2)
plot(wnt,h)
hold on
grid on
end
