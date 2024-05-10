clc
clear
close all

N = 4; % Define the number of points for the DFT

xo = [1 2 3 4]; % Define the input signal with N points
xeo = zeros(1,N);
xeo(1:2:end) = xo(1:2:end); 
xeo(2:2:end) = xo(2:2:end);
xeo = xeo';

W = exp(-1i*(2*pi/N)); % Calculate the rotation factor based on N

% Compute the butterfly diagram and DFT using Radix-2 DIT FFT algorithm
[X, butterfly] = dit_fft(xeo, N, W);

% Display the computed DFT
disp('Computed DFT:');
disp(X.');

% Draw the butterfly diagram
figure;
draw_butterfly(butterfly, N);

function [X, butterfly] = dit_fft(x, N, W)
    % Radix-2 Decimation-in-Time (DIT) FFT algorithm

    % Initialize the butterfly matrix
    butterfly = zeros(log2(N), N);

    % Bit-reverse the input sequence
    x_bitreversed = bitrevorder(x);

    % Perform the FFT iterations
    for stage = 1:log2(N)
        % Number of butterflies at this stage
        n_butterflies = 2^(stage - 1);

        % Size of each butterfly group
        group_size = N / (2^stage);

        % Twiddle factor exponent increment
        twiddle_exp_inc = 2^(stage - 1);

        % Perform butterflies at this stage
        for group = 1:n_butterflies
            % Butterfly index range
            idx_range = (group - 1) * group_size + (1:group_size);

            % Compute butterflies
            for k = 1:group_size
                even_idx = idx_range(k);
                odd_idx = even_idx + group_size;

                % Compute twiddle factor
                twiddle_exp = (k - 1) * twiddle_exp_inc;
                twiddle = W^twiddle_exp;

                % Perform butterfly operation
                x_even = x_bitreversed(even_idx);
                x_odd = x_bitreversed(odd_idx);
                butterfly(stage, even_idx) = x_even + twiddle * x_odd;
                butterfly(stage, odd_idx) = x_even - twiddle * x_odd;
            end
        end

        % Update the bit-reversed sequence for the next stage
        x_bitreversed = butterfly(stage, :);
    end

    % Extract the final DFT result
    X = butterfly(end, :);
end

function draw_butterfly(butterfly, N)
    % Draw the butterfly diagram

    % Set up the plot
    hold on;
    grid on;
    title('Butterfly Diagram');
    xlabel('Real');
    ylabel('Imaginary');
    axis equal;

    % Plot the initial points
    plot(butterfly(1, :), 'ko', 'DisplayName', 'Input');

    % Plot the intermediate stages
    for stage = 1:size(butterfly, 1)
        plot(butterfly(stage, :), 'o', 'DisplayName', ['Stage ', num2str(stage)]);
    end

    % Plot the final DFT points
    plot(butterfly(end, :), 'r*', 'DisplayName', 'DFT');

    % Plot connections between stages
    for stage = 1:size(butterfly, 1)-1
        for idx = 1:N
            next_idx = bitrevorder(idx);
            next_idx_bin = dec2bin(next_idx-1, log2(N));
            next_idx_bin_flipped = fliplr(next_idx_bin);
            next_idx_flipped = bin2dec(next_idx_bin_flipped) + 1;
            next_idx_flipped_bitrev = bitrevorder(next_idx_flipped);

            line([real(butterfly(stage, idx)), real(butterfly(stage+1, next_idx_flipped_bitrev))], ...
                [imag(butterfly(stage, idx)), imag(butterfly(stage+1, next_idx_flipped_bitrev))], ...
                'Color', 'b');
        end
    end

    % Highlight connections for the final DFT points
    for idx = 1:N
        next_idx = bitrevorder(idx);
        next_idx_bin = dec2bin(next_idx-1, log2(N));
        next_idx_bin_flipped = fliplr(next_idx_bin);
        next_idx_flipped = bin2dec(next_idx_bin_flipped) + 1;
        next_idx_flipped_bitrev = bitrevorder(next_idx_flipped);

        line([real(butterfly(end, idx)), real(butterfly(end, next_idx_flipped_bitrev))], ...
            [imag(butterfly(end, idx)), imag(butterfly(end, next_idx_flipped_bitrev))], ...
            'Color', 'r', 'LineWidth', 2);
    end

    % Add legend
    legend('Location', 'best');
    hold off;
end
