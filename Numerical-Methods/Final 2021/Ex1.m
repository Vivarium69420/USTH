%% a,
%% i,
11^3 + factorial(15) - sqrt(076);
%% ii,
x = [1;2;3;4;5];
x'
%% ii,
x = [1;2;3;4;5];
x'
%% b,
%% i,
A = [1 2 3; 4 5 6; 7 8 0];
B = [1 1 076; 0 1 0; 0 0 1];
A + B
%% ii, 
C = A+B;
C'
%% iii,
D = (A-B);
D
inv(D)
%% iv, (remove row 3 and col 3)
D(3,:) = [];
D(:,3) = [];
D
%% c,
x = [0:1:30];
f = @(x) 2*x+5;
y = f(x);
plot(x,y)
%% d,
syms x;
eqn = sqrt(x) - x +1;
S = solve(eqn);
Y = double(S)

