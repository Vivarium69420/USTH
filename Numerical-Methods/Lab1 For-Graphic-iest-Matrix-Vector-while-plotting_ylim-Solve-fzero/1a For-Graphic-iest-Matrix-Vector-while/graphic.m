x = linspace(-5,5);
y1 = x+1;
y2 = -x+2;
plot(x,y1,'color', 'red');
hold on;
plot(x,y2, 'color', 'green', 'marker', '.');
title('Graphic guide');
xlabel('x');
ylabel('y');
legend('y=x+1', 'y=-x+2', 'location','best')