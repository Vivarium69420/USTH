%% Ex1
%% a,
c = 0;
n = input('Enter n: ');
while n>0
    c = c+1;
    n = n-1;
end
disp("There are " + c + " number"); 
    
%% b,
count = 0;
n = input('Enter n: ');
while n>0
    if rem(n,2) == 0
        count;
    else
        count = count +1;
    end 
    n = n -1;
end
disp("Number of odd numbers: " +count);
%% Ex2
sum = 0;
i = 0;
while sum <20
    sum = sqrt(2)*i -1;
    i = i+1;
end
sum
%% Ex3
i = 0.1; %interest rate
t = 0;
F = input('Enter the money invested: ');
double_F = 2*F;
while F<double_F
    F = F + F*i;
    t = t+1;
end
t