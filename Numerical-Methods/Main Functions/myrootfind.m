function [a,b] = myrootfind(f,a0,b0)
    %f: function
    %a0, b0: left and right edges of the domain
    %a,b: arrays that give the l-r edges of subintervals
    n = 1001; % # test points
    a = [];
    b = [];
    x = linspace(a0,b0,n);
    y = f(x);
    for i = 1:(n-1)
        if y(i)*y(i+1) <= 0
            a = [a x(i)];
            b = [b x(i+1)];
        end
    end
    if size(a,1) == 0
        warning("no roots were found")
    end
end
            