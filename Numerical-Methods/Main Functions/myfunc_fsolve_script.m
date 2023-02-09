clc
clear all
fun = @myfun2eq;
x0 = [1.5,1.5];
options = optimset('display','iter');
[x,fval] = fsolve(fun,x0,options);
