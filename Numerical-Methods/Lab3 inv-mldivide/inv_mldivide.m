A = [2 1 -1; -3 -1 2; -2 1 2];
B = [8;-11;-3];
x = inv(A)*B
y = mldivide(A,B)