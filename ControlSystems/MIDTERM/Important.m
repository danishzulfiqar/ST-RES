% Define the corrected plant transfer function
plant = tf([1], [1 0.02 25.0001]);

% Step response of the plant
figure;
step(plant);
title('Step Response of the Plant');

% Root locus of the plant
figure;
rlocus(plant);
title('Root Locus of the Plant');
grid on;

% Assuming you are trying to find a proportional controller gain K
% that achieves a certain closed-loop performance,
% start with an initial guess for K and adjust as needed:
K = 1; % This is an initial guess, you will need to adjust it based on your design requirements

% Open-loop transfer function
sys_ol = series(tf([K], [1]), plant);

% Closed-loop transfer function with unity feedback
sys_cl = feedback(sys_ol, 1);

% Step response of the closed-loop system
figure;
step(sys_cl);
title('Step Response of the Closed-Loop System');

% Root locus of the open-loop system
figure;
rlocus(sys_ol);
title('Root Locus of the Open-Loop System');
grid on;
