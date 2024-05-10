s = tf('s'); % Define the Laplace variable s
K = 1; % Start with a gain of 1 (it will be varied in the root locus plot)

% Define the open-loop transfer function G(s)H(s)
G = K * (2*(s+1)) / (s^3 + 7*s^2 + 10*s);

% Plot the root locus
figure;
rlocus(G);
title('Root Locus of the System');
grid on;

% If you need to determine the range of K for stability,
% you can find the range of gains for which the poles of the closed-loop
% system are in the left half of the s-plane.
