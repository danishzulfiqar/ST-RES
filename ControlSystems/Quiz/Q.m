poles = [-0.1 + 5j, -0.1 - 5j];
zeros = [-10];

num = poly(zeros);
den = poly(poles);
G = tf(num, den);

rlocus(G);

num_poles = length(poles);
num_zeros = length(zeros);

centroid = (sum(real(poles)) - sum(real(zeros))) / (num_poles - num_zeros);
number_of_asymptotes = num_poles - num_zeros;
angles = (2*(0:(num_poles - num_zeros - 1)) + 1) * 180 / (num_poles - num_zeros);


