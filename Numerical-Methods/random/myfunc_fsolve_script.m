clc
clear all
fun = @root2d;
x0 = [0,0];
[x,fval] = fsolve(fun,x0);
