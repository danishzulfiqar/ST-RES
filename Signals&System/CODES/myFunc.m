function A = myFunc(x,y)
if length(x)>length(y)
    a = length(x)-length(y);
    
    y = [y,zeros(a)];
    
elseif length(y)>length(x)
    a = length(y)-length(x);
    
    x = [x,zeros(a)];
    
end

z = x+ y


    
    