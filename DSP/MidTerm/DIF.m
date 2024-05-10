clc
clear
close all

N = 4; % Define the number of points for the DFT
M = N/2; % Calculate the size of the transform matrices

xo = [1 0 -1 0]; % Define the input signal with N points
xeo = zeros(1,N);

% Reverse the bit-reversed indices to obtain the original sequence
xeo(1:2:N) = xo(1:M); 
xeo(2:2:N) = xo((M+1):N);

W = exp(-j*(2*pi/N)); % Calculate the rotation factor based on N

TF = zeros(N,N);
for k = 1:N
    for n = 1:N
        TF(k,n) = W^((k-1)*(n-1));
    end
end
TF = conj(TF); % Conjugate the TF matrix for DIF FFT

Ffour = zeros(M,M);
f = 1;
for c = 1:2:N-1
    Ffour(:,f) = TF(1:M,c);
    f = f+1;
end

TFR = zeros(M,M);
for d = 1:M
    TFR(d,d) = W^(d-1);
end
TFR = conj(TFR); % Conjugate the TFR matrix for DIF FFT

TFM = [eye(M,M) zeros(M,M); zeros(M,M) TFR];
FfourM = [Ffour zeros(M,M); zeros(M,M) Ffour];

I = [eye(M,M) eye(M,M); eye(M,M) -1*eye(M,M)];

X = I.*TFM.*FfourM.*xeo;
[X, conj(fft(xo,N)')]
