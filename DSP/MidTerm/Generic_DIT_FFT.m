clc
clear
close all

xo = [-1 0 2 0 -4 0 2 0]; 

N = length(xo);
M = N/2; 

xeo = zeros(1,N);
xeo(1:M) = xo(1:2:N); 
xeo((M+1):N) = xo(2:2:N); 
xeo = xeo';

W = exp(-j*(2*pi/N)); 

TF = zeros(N,N);
for k = 1:N
    for n = 1:N
        TF(k,n) = W^((k-1)*(n-1));
    end
end
TF

Ffour = zeros(M,M);
f = 1;
for c = 1:2:N-1
    Ffour(:,f) = TF(1:M,c);
    f = f+1;
end
Ffour

TFR = zeros(M,M);
for d = 1:M
    TFR(d,d) = W^(d-1);
end
TFR

TFM = [eye(M,M) zeros(M,M); zeros(M,M) TFR];
FfourM = [Ffour zeros(M,M); zeros(M,M) Ffour];

I = [eye(M,M) eye(M,M); eye(M,M) -1*eye(M,M)];

X = I*TFM*FfourM*xeo;
[X, conj(fft(xo,N)')]
