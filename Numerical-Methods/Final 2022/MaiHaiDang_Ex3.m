%% a,
clear all
% Define matrix of coefficients
A = [20,5;0.04,0.12;1,1];
B = [9500;40;550];
%Define objective equation coefficient
f = [-45, -20];
%Solve for x, P
x = linprog(f,A,B)
P  = -f*x;
%% b,
clear all
func = @(x) 2 + x.^3 + exp(2.*x+1);
h1 = 0.1;
h2 = 0.01;
x = 0.5; % the point to evalute difference
dxForward_h1 = (func(x+h1)-func(x))/h1
dxBackward_h2 = (func(x+h2)-func(x))/h2
%% c,
clear all
x = linspace(0,0.8);
f = 76 +25.*x-x.^2;
y_1 = trapz(x,f)
f_1 = @(x)76 +25.*x-x.^2;
y_2 = quad(f_1,0,0.8)