function [even_component, odd_component] = decompose_sequence(sequence)

    N = length(sequence);

    even_component = zeros(1, N);
    odd_component = zeros(1, N);
    
    for n = 1:N
        even_component(n) = 0.5 * (sequence(n) + sequence(N + 1 - n));
        odd_component(n) = 0.5 * (sequence(n) - sequence(N + 1 - n));
    end
end
