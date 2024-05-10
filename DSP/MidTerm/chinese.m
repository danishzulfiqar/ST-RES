clear variables;
close all;
clc;

b = [5 7 9]; % the bases should be relativly prime
g = [4 3 1]; % the number represention (g) encryted in a unique way


% Objective: To find the smallest x such that: 
% a. g=mod(x,b) or written in another way
% b. x =(%b) g  

[bx by] = meshgrid(b, b);
bb = gcd(bx,by)-diag(b);
pp = ~sum(sum(bb>1)); 

if (pp)
    display(['The Bases [relativly prime] are: b=[' num2str(b) ']'])
    display(['The Number [representation] is : g=<' num2str(g) '>' ])
    
    % take out one by one bases and replace with 1's 
    xo = by-diag(b-1);
    
    % and get the product of the others
    Mk = prod(xo);
    
    % now we should get an solution for x and xa where Mk.*xa =(%b) x =(%b) 1
    % note that xa.*g is a solution, i.e xa.*g =(%b) g, because xa =(%b) ones
    [Gk, nk, Nk] = gcd ( b, Mk ) ;
    % [G,C,D] = GCD( A, B ) also returns C and D so that G = A.*C + B.*D.
    % These are useful for solving Diophantine equations and computing
    % Hermite transformations.
    
    % Then the strange step
    Sum_g_Nk_Mk = sum ( (g .* Nk) .* Mk ) ;
    
    % get the lowest period unique answer between [0:(product(b)-1)]
    x = mod(Sum_g_Nk_Mk,prod(b));
    
    display(['The Number [lowest unique value] is: x=''' num2str(x) '''' ])
else
    display('The Bases are NOT Relprime.')
end
