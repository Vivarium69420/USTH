%% Ex1
x = [1 2 3 4 5];
x(3)+x(2);
%% Ex2
x= [1;2;3;4;5];
y = x';
disp(y);
%% Ex3:
a = 1:100;
sum(a);
%% Ex4
syms x y;
x = 1;
y = 2;
f2 = x+y;
display(f2);
%% EX5
syms k;
f = (1/k -1/(1+k));
m = symsum(f,k,1,Inf);
display(m);
syms n;
f1 = (1/n^2);
n = symsum(f1,k,1,Inf);
display(n);
