% Sampling and Reconstruction 
clc
clear 
close all
% Creating modulating signal
fm=2;         % message signal frequency (Hz)
n=50;         % factor of sampling frequency
K=1000;
Ts=1/(n*fm);              % sampling time
t=0:Ts:100-Ts;            % time range
N=size(t,2);
Fs=1/Ts;                  % sampling frequency
dFs=Fs/N;
f=-Fs/2:dFs:Fs/2-dFs;
m=2*cos(2*pi*fm*t);       % message signal
subplot(5,1,1);
plot(t,m);
xlabel('Time(in s)');
title('Modulating signal');
% Frequency Domain
M=fftshift(fft(m)); % FFT of the message signal
subplot(5,1,2)
plot(f,abs(M)/N);
xlabel('Frequency(in hertz)');
title('Magnitude response');
%sound(X)
% Pulse train generation
T=0.2;    %sampling interval
F=1/T;    % sapling frequency
h=zeros(1,length(t));  % initialize all values to zero
for k=-K:1:K
h=h+(1/T)*cos(2*pi*k*F*t);
end
h_a=T*h/(2*K+1);   % scaling 
subplot(5,1,3);
plot(t,h_a);
xlabel('Time(s)');
title('Pulse train');
% sampling
m_samp=m.*h_a;
N_samp=length(m_samp);
subplot(5,1,4);
xlabel('Time(in s)');
title('Sampled value');
% Magnitude response of sampled signal
M_samp=fftshift(fft(m_samp)); 
subplot(5,1,5)
plot(f,abs(M_samp)/N_samp);
xlabel('Frequency(in hertz)');
title('Magnitude response')