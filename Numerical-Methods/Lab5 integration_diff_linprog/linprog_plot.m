% Define matrix of coefficients
A = [7,11;10,8;1,0;0,1];
B = [77;80;9;6];
%Define objective equation coefficient
f = [-150, -175];
%Solve for x, P
x = linprog(f,A,B);
P  = f*x;
%% ploting feasible region
x = linspace(0,9);
y = linspace(0,6);

[X,Y] = meshgrid(x,y);
cond1 = 7*X + 11*Y <77;
cond2 = 10*X +8*Y <80;
cond = cond1.*cond2;
surf(X,Y,cond);
view(0,90);
%%
clear all;
A = [1,1;-0.1,-0.15;-0.75,-0.7];
B = [7;-0.65;-4];
f = [0.4;0.45];
lb = zeros(2,1);
[x,fval] = linprog(f,A,B,[],[],lb);