f1 = @(x, y) (x.^2 + x*y - 10);
f2 = @(x, y) (y + 3*x*y.^2 - 57);
% Replace ezplot (old) by fimplicit (new)
fimplicit(f1);
hold on
fimplicit(f2);
title('Guessing solution using graph');
xlabel('x');
ylabel('y');
legend('Eq1', 'Eq2', 'location', 'best');