x = [0,1,2,3,4,5];
y = [3,6,8,11,13,14];
f = polyfit(x,y,1);
fit_eval = polyval(f, x);
plot(x,y,'ko');
hold on;
plot(x,fit_eval,'color','blue');
hold on;
%%
clear all;
x = 1:1:5;
y = [5.5 43.1 128 290.7 498.4];
f = polyfit(x,y,2);
%%
clear all;
f = [-5;-10];
A = [1 0;2 3; 1 1];
b = [6;19;8];
lb = zeros(2,1);
[x,fval] = linprog(f,A,b,[],[],lb);