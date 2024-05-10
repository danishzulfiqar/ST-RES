clc
clear
close all

x = [1 2 3 4 5 6 7 8];
N = length(x);
p=log2(N);
Half=N/2;

for stage=1:p
    for index=0:(N/(2^(stage-1))):(N-1)
        for n=0:(Half-1)
            pos=n+index+1;
            pow=(2^(stage-1))*n;
            w=exp((-1i)*(2*pi)*pow/N);
            a=x(pos)+x(pos+Half);
            b=(x(pos)-x(pos+Half)).*w;
            x(pos)=a;
            x(pos+Half)=b;
        end
    end
    Half=Half/2;
end

y=bitrevorder(x);

disp(y);