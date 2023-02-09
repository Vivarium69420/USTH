x = [0.00000 ,0.78540 ,1.57080 ,2.35619,3.14159 ,3.92699 ,4.71239 ,5.49779 ,6.28319]; 
y = [0.00000, 0.70711, 1.00000, 0.70711, 0.00000, -0.70711, -1.00000, -0.70711, 0.00000];

p1 = 3.00000;
p2 = 4.50000;
% method = 'nearest';
% method = 'cubic';
method = 'spline';
vq1 = interp1(x,y,p1,method);
vq2 = interp1(x,y,p2,method);

plot(x,y);
hold on;
plot(p1,vq1,'o', "color", "green");
hold on;
plot(p2,vq2,'o', "color", "red");

