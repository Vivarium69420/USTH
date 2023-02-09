clc
clear all
close all

u=@(x,y) -x^2+y-1;
v=@(x,y) -2*cos(x)+y-1;
dux=@(x,y) -2*x;
duy=@(x,y) 1;
dvx=@(x,y) 2*sin(x);
dvy=@(x,y) 1;

x0 = 1;
y0 = 1;
ex = 0.0001;
ey = 0.0001;
ite = 3;
count = 0;

for i = 1:ite
    count = count +1;
    x = x0 - (u(x0, y0)*dvy(x0, y0) - v(x0, y0)*duy(x0, y0))/(dux(x0, y0)*dvy(x0, y0) - duy(x0, y0)*dvx(x0, y0));
    y = y0 - (v(x0, y0)*dux(x0, y0) - u(x0, y0)*dvx(x0, y0))/(dux(x0, y0)*dvy(x0, y0) - duy(x0, y0)*dvx(x0, y0));
    errorx = abs((x-x0)/x);
    errory = abs((y-y0)/y);
    if errorx <= ex
        break
    end
    if errory <= ey
        break
    end
    x0 = x;
    y0 = y;
    
end
x
y
errorx
errory
count
