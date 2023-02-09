%% Ex1
%% a,
s = 0;
for i=1:1000
    s = s + i.^2;
end
s
%% b,
factorial(20)
%% c,
s=0;
for i=i:502
    s = s+ (-1)^(i-1)*(1/2^(i-1));
end

%% d,
syms n;
f= 1/((2*n-1)^2*(2*n+1)^2);
res = symsum(f,n,1,Inf);
display(res);
%% Ex2:
n = input('Enter n: ');
k = input('Enter k: ');
for i = 1:Inf
    if(n<k)
        disp("n need to be bigger than k, enter again");
        n = input('Enter n: ');
        k = input('Enter k: ');
    else
        break;
    end
end
combination = factorial(n)/(factorial(k)*(factorial(n-k)));
permutation = factorial(n)/factorial(n-k);
combination
permutation
