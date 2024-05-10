clc
close all

n = -2:2;
sequence = [1, 2, 3, 4, 5];
[even_component, odd_component] = decompose_sequence(sequence);

disp('Even Component:');
disp(even_component);
disp('Odd Component:');
disp(odd_component);

stem(n, even_component);
