function [x,n]=rampseq(n0,n1,n2)
n=n1:n2;
n0=0;
x=n.*(n>=n0);
%x(n<=n0)=0;
stem(n,x)
title('rampseq')
xlabel('n')
ylabel('x[n]')
end
