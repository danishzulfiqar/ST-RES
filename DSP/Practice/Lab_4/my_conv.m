function y = my_conv(x, h)
    % Computes the convolution of two sequences x and h.
    % Handles sequences with values for t < 0.

    % Reverse the impulse response h[n]
    h_reversed = fliplr(h);

    % Initialize the output sequence y[n]
    y = zeros(1, length(x) + length(h) - 1);

    % Perform convolution
    for n = 1:length(y)
        for k = 1:length(h_reversed)
            if n - k >= 1 && n - k <= length(x)
                y(n) = y(n) + x(n - k + 1) * h_reversed(k);
            end
        end
    end
end

