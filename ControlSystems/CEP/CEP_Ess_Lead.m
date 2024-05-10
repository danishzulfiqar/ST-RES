% Define the plant G(s) and compensator K(s)
s = tf('s');
G = (s+3)/(s*(s+1)*(s+2)*(s+4));
Kle = 2.5*((s+1.5)/(s+4));

% Calculate the open-loop transfer function
L = Kle * G;

% Calculate the position error constant Kp for the step input
Kp = dcgain(L);

% Calculate the steady-state error for the step input
ess_step = 1/(1+Kp);

% Since the system is type 1, the steady-state error for a step disturbance is zero
ess_disturbance = 0;

% Display the steady-state errors
disp(['The steady-state error for a step reference input is: ', num2str(ess_step)]);
disp(['The steady-state error for a step disturbance input is: ', num2str(ess_disturbance)]);
