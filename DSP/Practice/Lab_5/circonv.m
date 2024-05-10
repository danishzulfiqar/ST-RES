function [y,N]=circonv(x,h)
l1=length(x);
l2=length(h);
N=max(l1,l2);
x=[x zeros(1,N-l1)];
h=[h zeros(1,N-l2)];
y=zeros(1,N);
for q=1:N
    for w=1:N
        t=mod(q-w,N);
        t=t+1;
        y(q)=y(q)+x(w)*h(t);
    end
end
end