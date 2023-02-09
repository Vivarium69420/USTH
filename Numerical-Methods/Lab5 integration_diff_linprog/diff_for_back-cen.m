func = @(x) 0.2 + 25*x - 200*x.^2 + 675*x.^3 - 900*x.^4 +400*x.^5;
dfunc = @(x) 25 - 400*x +2025*x.^2 -3600*x.^3 + 2000*x.^4;

exact_val = dfunc(0.5) %derivative at 0.5

%---numerial diff----
step = 0.01;
x = 0:step:1;
y = func(x);
dy = diff(y)/step;
p = 51; %the position where x = 0.5
d = dy(p);

%---ForBacCen---
h = 0.01; %step 
x = 0.5; %init x
dxForward = (func(x+h)-func(x))/h
dxBackward = (func(x)-func(x-h))/h
dxCentral = (func(x+h)-func(x-h))/(2*h)

%---Error---
er_For= abs((exact_val-dxForward)/exact_val)*100
er_Bac= abs((exact_val-dxBackward)/exact_val)*100
er_Cen= abs((exact_val-dxCentral)/exact_val)*100