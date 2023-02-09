%% solve, fzero
%% a,b,
f = @(x) 67*x +32;
S = solve(f); % Solve
c = double(S); % numerical value of solve
format long;
y = fzero(f,0); %fzero
%% c,
syms x q p
f = x^3 + p*x +q;
% to explicitly display the root, use 'MaxDegree' option
% and set it to the desire root
S = solve(f,x,'MaxDegree',3)
%% d,
f =@(x) exp(x) - 8*x +4;
S = solve(f,x,'real',true);
y = fzero(f,0);
