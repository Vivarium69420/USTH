function [ a0,a1,r2 ] = linear_regression( x, y )
%UNTITLED2 Summary of this function goes here
% Detailed explanation goes here
% Linear regression: y = a0 + a1.x
% x: independent variable
% y: dependent variable
% r2: coefficient of determination
if length(x)~=length(y)
fprintf('The independent and the dependent variables');
should ('have same number of elements');
else
n=length(x); % The number of data
end
X=mean(x); Y=mean(y);
a1=(x*y'/n-X*Y)/var(x);
a0=Y-a1*X;
r2= (n*x*y'-n*X*n*Y)/sqrt((n*x*x'-(n*X)^2)*(n*y*y'-(n*Y)^2));
% Create the best fit line
xp=linspace(min(x),max(x),2);
yp=a0+a1*xp;
plot(x,y,'o',xp,yp,'b');
end