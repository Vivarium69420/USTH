%% a,
%% i,
T = [-50; -30; 0; 60; 90; 110];
c = [1270; 1280;1350; 1480; 1580;1700];
f = fit(T,c,'poly1');
c_1 = f(100)
plot(f,T,c);
hold on
%% ii,
T = [-50; -30; 0; 60; 90; 110];
c = [1270; 1280;1350; 1480; 1580;1700];
f = polyfit(T,c,1);
c_1 = polyval(f,100) %c at T = 100
y = polyval(f,T);
plot(T,c,'.');
hold on;
plot(T,y)
%% iii,
T = [-50; -30; 0; 60; 90; 110];
c = [1270; 1280;1350; 1480; 1580;1700];
a0 = [0,0];
s = lsqcurvefit(@(f,x)f(1)*x +f(2),a0,T,c);
func = @(x) s(1)*x + s(2);
z = func(100)
plot(T,c,'o');
hold on;
w = linspace(T(1), T(end));
plot(w, func(w), 'color', 'blue')
%% b,
h1 = 0.1; %step 1
h2 = 0.01; %step 2
x = 0.5; %init x
f = @(x) 2 + x^2 + exp(2*x+1);
dxForward_1 = (f(x+h1)-f(x))/h1
dxForward_2 = (f(x+h2)-f(x))/h2
%% c,
%% i,
x = linspace(0,0.8);
func = 076 +25*x - x.^2;
y = trapz(x,func);
%% ii,
f = @(x)076 +25*x - x.^2;
yb = quad(f,0,0.8)
%% iii,
a = 0;
b = 0.8;
f = @(x)076 +25*x - x.^2;
two_point_gauss = ((b-a)/2)*f(((b-a)/2)*(-1/sqrt(3))+(b+a)/2)+((b-a)/2)*f((((b-a)/2)*(1/sqrt(3))+(b+a)/2))

