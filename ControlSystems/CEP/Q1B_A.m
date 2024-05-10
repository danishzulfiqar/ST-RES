% Define the open-loop transfer function L(s)
numL = [1 3]; % Replace with your numerator coefficients
denL = conv(conv([1 0], [1 1]), [1 2, 1 4]); % Replace with your denominator coefficients
L = tf(numL, denL);

% Plot the root locus
figure;
rlocus(L);
title('Root Locus of L(s)');

% You can use [K, poles] = rlocfind(L) to interactively find the value of K
% for a specific point on the root locus plot.
