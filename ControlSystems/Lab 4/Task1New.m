clc
clear
close all

system_tf = tf([1 1 2], [1 1 3 1 1]);
time_span = 0:0.001:10;

[step_response, time] = step(system_tf);
plot(time, step_response, 'linewidth', 2), grid on;
title('Step Response');
xlabel('Time');
ylabel('Amplitude');

figure();

[impulse_response, time] = impulse(system_tf);
plot(time, impulse_response, 'linewidth', 2), grid on;
title('Impulse Response');
xlabel('Time');
ylabel('Amplitude');

figure();

ramp_input = time;
[response_ramp, time] = lsim(system_tf, ramp_input, time);
plot(time, response_ramp, 'linewidth', 2), grid on;
hold on;
plot(time, ramp_input, 'linewidth', 2), grid on;
legend('output', 'input');
title('Ramp Response');
xlabel('Time');
ylabel('Amplitude');

figure();

sinusoidal_input = sin(time);
[response_sinusoidal, time] = lsim(system_tf, sinusoidal_input, time);
plot(time, response_sinusoidal, 'linewidth', 2), grid on;
hold on;
plot(time, sinusoidal_input, 'linewidth', 2), grid on;
legend('output', 'input');
title('Sinusoidal Response');
xlabel('Time');
ylabel('Amplitude');

figure();

parabolic_input = time.^2/2;
[response_parabolic, time] = lsim(system_tf, parabolic_input, time);
plot(time, response_parabolic, 'linewidth', 2), grid on;
hold on;
plot(time, parabolic_input, 'linewidth', 2), grid on;
legend('output', 'input');
title('Parabolic Response');
xlabel('Time');
ylabel('Amplitude');
