clear all;
f = @(x) 0.2 +25*x -200*x.^2+ 675*x.^3 - 900*x.^4 +400*x.^5;
df = @(x) 25 - 400*x + 3*675*x.^2 - 4*900*x.^3 + 5*400*x.^4;

%calculate derivative at x = 0.5;
exact_derivative = df(0.5);

%------Numerical Diff------%
step = 0.01;
x = 0:0.01:1; %generate x
y = f(x); %define function
d = diff(y)/step; %calculate derivative
p = 51; %location of 0.5 in x array 
dp = d(p);

c = forward(y,x,p);
g = backward(y,x,p);
w = central(y,x,p);