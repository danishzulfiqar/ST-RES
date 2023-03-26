function [x,n]=stepseq(n0,n1,n2)
n=n1:n2;
n0=0;
x(n>=n0)=1;
x(n<=n0)=0;
stem(n,x)
title('stepseq')
xlabel('n')
ylabel('x[n]')
end
