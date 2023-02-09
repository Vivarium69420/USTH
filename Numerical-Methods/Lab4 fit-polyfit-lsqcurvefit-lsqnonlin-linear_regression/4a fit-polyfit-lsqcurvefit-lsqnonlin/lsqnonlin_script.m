x_data = 0.1:0.1:1;
y_data = [1.6781, 1.5711,1.4771,1.3945,1.3220, 1.2584, 1.2025,1.1534,1.1104, 1.0725];

myfun = @(t) exp(-t*x_data) +0.8 - y_data;
t0 = 0.5;
lb = 0.1;
ub = 200;
t = lsqnonlin(myfun,t0,lb,ub);
disp(t);
plot(x_data, y_data, 'ko');
hold on;
plot(x_data, exp(-t*x_data) +0.8, 'color','blue');
title("Kagawa particle curve fitting");
xlabel('x');
ylabel('y');