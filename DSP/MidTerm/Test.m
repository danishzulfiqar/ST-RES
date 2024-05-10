clc
clear
close all

% xo = rand(1,8);
% xo = [1 2 3 4 5 6 7 8];
xo = [-1 0 2 0 -4 0 2 0];
xeo = zeros(1,8);
xeo(1:4) = xo(1:2:8); 
xeo(5:8) = xo(2:2:8);
xeo = xeo';

W = exp(-j*(2*pi/8));

TF = zeros(8,8);
for k = 1:8
    for n = 1:8
        TF(k,n) = W^((k-1)*(n-1));
    end
end
TF

Ffour = zeros(4,4);
f = 1;
for c = 1:2:7
    Ffour(:,f) = TF(1:4,c);
    f = f+1;
end
Ffour

TFR = zeros(4,4);
for d = 1:4
    TFR(d,d) = W^(d-1);
end
TFR

TFM = [eye(4,4) zeros(4,4); zeros(4,4) TFR];
FfourM = [Ffour zeros(4,4); zeros(4,4) Ffour];

I = [eye(4,4) eye(4,4); eye(4,4) -1*eye(4,4)];

X = I*TFM*FfourM*xeo;
[X, conj(fft(xo,8)')]
