%% a,
clear all
Mass = [400;70;45;2;0.3;0.16];
Metabolism = [270;82;50;4.8;1.45;0.97];
% Linear model Poly1:
%      f(x) = p1*x + p2
% Coefficients (with 95% confidence bounds):
%        p1 =      0.6599  (0.5356, 0.7842)
%        p2 =       11.29  (-9.44, 32.02)

x = 200;
y = 0.6599*x+ 11.29
%% b,
clear all
func = @(x) x.^2 - 76;
dfunc = @(x) 2*x
xr = 1;
es = 0.0001;
maxit = 10;
[root, ea, iter] = newtraph(func,dfunc,xr,es,maxit)
%% c,
clear all
s=0;
for i=i:502
    s = s+ (-1)^(i-1)*(1/2^(i-1));
end
disp(s);
%% d,
clear all
A = [1 -2 3; -1 3 -1; 2 -5 5];
B = [9;-6;17];
x1 = inv(A)*B
x2 = mldivide(A,B)
[L,U] = lu(A);
x3 = L*U;
x3(:,1)
