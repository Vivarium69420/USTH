%% Ex1
a = 'Input: ';
n = input(a);
m=0;
if(n>1)
    m = n+1;
else
    m =n-1;
end
display(m);
%% Ex2
x = input('Enter a number: ');
y=0;
if (0<x)&&(x<10)
    y = 4*x;
elseif (10<x)&&(x<40)
    y = 10*x;
else
    y= x;
end
y
%% Ex3
syms y x
x = input('Enter the number of kWh: ');
if (x > 0 && x <= 50)
y = 1484 * x;
elseif (x > 50 && x <= 100)
y = 1484*50 + 1533*(x-50);
elseif (x > 100 && x <= 200)
y = 1484*50 + 1533*50 + 1786*(x - 100);
elseif (x > 200 && x <= 300)
y = 1484*50 + 1533*50 + 1786*100 + 2242 * (x - 200);
elseif (x > 300 && x <= 400)
y = 1484*50 + 1533*50 + 1786*100 + 2242 * 100 + 2503 * (x - 300);
elseif (x > 400)
y = 1484*50 + 1533*50 + 1786*100 + 2242 * 100 + 2503 * 100 + 2587*(x - 400);
else
disp("Invalid")
end
disp(y);