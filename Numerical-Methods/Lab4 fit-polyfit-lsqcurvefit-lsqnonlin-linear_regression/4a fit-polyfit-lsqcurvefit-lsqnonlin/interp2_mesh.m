x = -3:1:3;
y = -3:1:3;
[X,Y] = meshgrid(x,y);
Z = peaks(X,Y);
% surf(X,Y);
Z1 = interp2(X,Y,Z,1.2,2.8);
Z2 = interp2(X,Y,Z,2.5,2.5);