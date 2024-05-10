% Define the numerator and denominator of the original transfer function
num = [2 2];
den = conv(conv([1 0 0], [1 2]), [1 5]);

% Plot the root locus
figure; % Open a new figure
rlocus(num, den); % This function already plots the root locus
hold on; % Hold the plot for multiple plots

% Additional points and root locus features can be added after plotting the root locus
plot(0, 0, 'rx'); % Plot the origin as a red cross
plot(-1, 0, 'go'); % Plot the point at s = -1 as a green circle
plot(-2, 0, 'rx'); % Plot the point at s = -2 as a red cross
plot(-5, 0, 'rx'); % Plot the point at s = -5 as a red cross

% Set the axis limits and turn on the grid
axis([-20 10 -15 15]);
grid on;

% Define symbolic variables for later analysis
syms s k w real;

% Create a symbolic transfer function
sys = tf(num, den);

% Multiply open-loop system by gain k (symbolic)
sys_ol = k * poly2sym(num, s) / poly2sym(den, s);

% Get the closed-loop transfer function (symbolic)
sys_cl = sys_ol / (1 + sys_ol);

% Extract numerator and denominator of the closed-loop transfer function (symbolic)
[Numc, Denc] = numden(sys_cl);

% Define the characteristic equation
ch_eq = Denc;

% Substitute s=jw (w=omega) into the characteristic equation
s = 1j * w;

% Substitute the characteristic equation with jw
res = subs(ch_eq);

% Set the real and imaginary parts to zero
E = [real(res) == 0, imag(res) == 0];

% Solve for w and k
S = solve(E, w, k);

% Evaluate w and k to numerical values
w = vpa(S.w);
k = vpa(S.k);

% You would typically use these w and k values to analyze stability or design controllers
% The specific use depends on the context of your control problem

% Note that the `rlocus` function plots the locus as the gain K varies from 0 to infinity
% If you need to find the root locations for a specific gain k, you would use the `rlocus` function like this:
% For example, let's use the second value of k (if it is valid)
if length(k) >= 2
    k_specific = double(k(2)); % Convert symbolic to double precision
    [roots, poles] = rlocus(num, den, k_specific); % Compute roots for specific gain
    disp('Roots for specific gain k:');
    disp(roots); % Display the roots
else
    disp('The solution for k does not exist or is not valid.');
end

% Finally, hold off the plot
hold off;
