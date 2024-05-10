clf; % Clear the graph on the screen.
numgh = [1 -4 20]; % Define the numerator of G(s)H(s).
dengh = poly([-2 -4]); % Define the denominator of G(s)H(s).
disp('G(s)H(s)'); % Display a label.
GH = tf(numgh, dengh); % Create G(s)H(s) and display.
rlocus(GH); % Draw the root locus.
z = 0.2:0.05:0.5; % Define damping ratio values: 0.2 to 0.5 in steps of 0.05.
wn = 0:1:10; % Define natural frequency values: 0 to 10 in steps of 1.
sgrid(z, wn); % Generate damping ratio and natural frequency grid lines for root locus.
title('Root Locus'); % Define a title for the root locus.
pause;
rlocus(GH); % Draw a close-up root locus.
axis([-3 1 -4 4]); % Define the range on axes for the close-up root locus view.
title('Close-up'); % Define a title for the close-up root locus.
z = 0.45; % Define the damping ratio line for overlay on the close-up root locus.
wn = 0; % Suppress natural frequency overlay curves.
sgrid(z, wn); % Overlay the damping ratio curve on the close-up root locus.
for k = 1:3 % Loop allows 3 points to be selected as per Example 8.7 (z=0.45, jwcrossing, breakaway).
    [K, p] = rlocfind(GH); % Generate gain, K, and closed-loop poles, p, for a point selected interactively on the root locus.
end % End loop.
pause;
