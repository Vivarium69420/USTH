%% a,
fun = @(x) ((2.2)^2*acos((2.2-x)/2.2)-(2.2-x)*sqrt(2*2.2*x-x^2))*5-8;
W = solve(fun)
%% b,
f = @(x) x.^2 - 76;
f1 = @(x) 2*x;
[root, ea, iter] = newtraph(f,f1,4,0.0001,50)
%% c,
a = 0;
n = 501;
for n = 0:501
    a = a +((-1)^n/(2*n+1));
end
disp(a);
%% d,
A = [2 1 4; 1 2 -5; 3 -2 -4];
B = [10;1;8];
x = mldivide(A,B)
y = inv(A)*B