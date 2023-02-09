%% fminbnd
f = @(x) -x.^3*exp(-x);
options = optimset('display','iter','tolfun',1e-8);
z = fminbnd(f,1,4,options);
x = linspace(1,4);
y = -x.^3.*exp(-x);
plot(x,y);
hold on;
plot(z,f(z),'*') %ploting the z(3,f(3)) which is z(x,y)
title('Labwork6 - 1');
xlabel('x');
ylabel('y');
legend('y=-x^3*exp(-x)','Minimum', 'location','best')

%% fminsearch
f = @(x) x(1)*x(2)*exp(-(x(1).^2+x(2).^2));
x0 = [2,2];
options = optimset('display', 'iter', 'tolfun',1e-8);
z = fminsearch(f,x0,options);
x = linspace(-2,2);
y = linspace(-2,2);

%plot using plot3
figure(1)
fxy = x.*y.*exp(-(x.^2+y.^2));
plot3(x,y,fxy); 
title('Labwork 6 - 2');
xlabel('x');
ylabel('y');
zlabel('f(x,y)');
legend('x*y*exp(-(x^2+y^2)','location','best')

%plot using surf
figure(2)
[X,Y] = meshgrid(x,y);
Z = X.*Y.*exp(-(X.^2+Y.^2));
surf(X,Y,Z);
title('Labwork 6 - 2');
xlabel('x');
ylabel('y');
zlabel('f(x,y)');

%% fzero & optimset 
f = @(x) exp(-x) - exp(-x.^3) +1;
options = optimset('display', 'iter', 'tolfun', 1e-4);
S = fzero(f,2,options)

x = linspace(-1,1);
y = exp(-x) - exp(-x.^3) +1;
plot(x,y,'red');
hold on;
plot(S, f(S), '*')
xlabel('x');
ylabel('y');
legend('exp(-x) - exp(-x.^3) +1','location','best');