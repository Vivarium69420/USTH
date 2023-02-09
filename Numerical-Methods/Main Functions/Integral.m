
clear all;
%generate x
x = linspace(0,0.8);
func = 0.2 +25*x -200*x.^2+ 675*x.^3 - 900*x.^4 +400*x.^5;
%calculate integral using trapz
y = trapz(x,func);
%calculate integral using cumtrapz
yb = cumtrapz(x, func);
%calculate integral using quad - simpson's method
f = @(x) 0.2 +25*x -200*x.^2+ 675*x.^3 - 900*x.^4 +400*x.^5;
yc = quad(f,0,0.8);
%calculate integral using quadapdapt
q = quadadapt(f,0,0.8,0.0001);