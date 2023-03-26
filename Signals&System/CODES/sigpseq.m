function [x,n]=sigpseq(n0,n1,n2) 
n=n1:n2;
n0=0;
x(n>=n0)=1;
x(n<=n0)=-1;
stem(n,x)
title('sigpseq')
xlabel('n')
ylabel('x[n]')
end
