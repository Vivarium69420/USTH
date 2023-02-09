syms x;
f = x^3 - 7*x +6;
c = sym2poly(f);
A = compan(c);
x = eig(A);
disp([x]);