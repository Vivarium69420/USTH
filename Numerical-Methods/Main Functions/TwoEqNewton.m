clc
clear all
close all
x=[1 1]';
N = 3;
for k=1:N
F=[ x(2) + 2*x(1)*x(1)-10; x(2)*x(2)*x(2) -3*x(1)+521];
A=[4*x(1), 1 ; 3 , 3*x(2)*x(2)];
dx=A\F;
x=x-dx;
k=k+1;
end
k;
x';
F';