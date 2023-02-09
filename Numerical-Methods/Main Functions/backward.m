function d = backward(y,x,p)
d = (y(p)-y(p-1))/(x(p)-x(p-1));
end