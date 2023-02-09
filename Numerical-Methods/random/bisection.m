function [root,fx,ea,iter] = bisection(func, xl,xu,es,maxit)
if nargin<3,error('at least 3 input arguments required'),end
test = func(xl)*func(xu);
if test>0,error('no sign change'),end
if nargin<4||isempty(es), es=0.0001;end
if nargin<5||isempty(maxit), maxit=50;end

iter = 0; xr = xl; ea = 100;
while (1)
xrold = xr;
xr = (xl + xu)/2;
iter = iter + 1;
if xr ~= 0,ea = abs((xr - xrold)/xr) * 100;end
test = func(xl)*func(xr);
if test < 0
xu = xr;
elseif test > 0
xl = xr;
else
ea = 0;
end
if ea <= es || iter >= maxit,break,end
end
root = xr;
fx = func(xr);