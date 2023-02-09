%% linear regression
clc,clear
mass = [400,70, 45, 2,   0.3,  0.16];
meta = [270, 82, 50, 4.8, 1.45,0.97];

[a0,a1,r2] = linear_regression(mass, meta);
tiger_mass = 350;
tiger_meta = a0 + a1*tiger_mass %guess the meta of the tiger with mass 350

%% polyfit
clc,clear
mass = [400,70, 45, 2,   0.3,  0.16];
meta = [270, 82, 50, 4.8, 1.45,0.97];

tiger_mass = 350;
f = polyfit(mass,meta,1);
f_val = polyval(f,mass);
tiger_val = polyval(f,tiger_mass)

plot(mass, meta, 'ko');
hold on;
plot(mass, f_val,'color','blue');
hold on;
plot(mass, tiger_val, 'marker', '*','color','red');
xlabel('Mass');
ylabel('meta');
legend('Raw data', 'fit line','Predicted tiger meta','location','southeast');