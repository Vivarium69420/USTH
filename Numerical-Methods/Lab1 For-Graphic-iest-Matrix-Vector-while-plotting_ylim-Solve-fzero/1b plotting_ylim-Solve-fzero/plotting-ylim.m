%% a.
x = linspace(-4,4);
y = x.^3 -x;
plot(x,y, 'red');
xlabel('x');
ylabel('y');
legend('y = x^3 - x', 'location', 'best');
%% b
x = linspace(-pi,pi);
y = tan(x/2);
plot(x,y,'blue');
ylim([-10 10]); %setting limit for y
title('Graphic test');
xlabel('x');
ylabel('y');
legend('y=tan(x/2)','location', 'best');
%% c
x = linspace(-1.5,1.5);
y1 = exp(-x/2);
y2 = x.^4 - x.^2;
plot(x,y1,'red');
hold on;
plot(x,y2,'blue');
title('Graphic test');
xlabel('x');
ylabel('y');
legend('y=tan(x/2)','location', 'best');
