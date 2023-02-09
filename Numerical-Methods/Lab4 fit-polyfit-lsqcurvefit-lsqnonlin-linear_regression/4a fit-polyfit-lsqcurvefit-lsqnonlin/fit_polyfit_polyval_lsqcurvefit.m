%% a. Using fit()
weight = [40;63;62;68;64;45;50;66;67];
JHI = [1450; 3817; 3708; 4300; 3950; 1896; 2339;4200; 4312];

S = fit(weight, JHI, 'poly1');
VL_JHI = S(72)

plot(S,weight,JHI);
title('Weight vs JHI');
xlabel('weight');
ylabel('JHI');
legend('Raw data', 'Fit line', 'location', 'best');
%% b. Using polyfit()
weight = [40;63;62;68;64;45;50;66;67];
JHI = [1450; 3817; 3708; 4300; 3950; 1896; 2339;4200; 4312];

f = polyfit(weight,JHI,1);%linear fitting
y = polyval(f,weight); %evaluate polynomial value at f to plot
z = polyval(f,72)

plot(weight,JHI,'.');
hold on;
plot(weight,y) %weight would be x and evaluated value is y
title('Weight vs JHI');
xlabel('weight');
ylabel('JHI');
legend('Raw data', 'Fit line', 'location', 'best');

%% c. Using lsqcurvefit()
weight = [40;63;62;68;64;45;50;66;67];
JHI = [1450; 3817; 3708; 4300; 3950; 1896; 2339;4200; 4312];
x0 = [0 , 0];
S = lsqcurvefit(@(f,x) f(1)*x + f(2),x0,weight,JHI)
func = @(x) S(1)*x + S(2);
sol = func(72)
x= linspace(weight(1), weight(end));
plot(weight,JHI,'ko');
hold on;
plot(x, func(x),'color', 'blue');
title('Weight vs JHI');
xlabel('weight');
ylabel('JHI');
legend('Raw data', 'Fit line', 'location', 'best');

