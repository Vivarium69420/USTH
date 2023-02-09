function [x,e] = mybisect(f,a,b,n)
    %f: funtion
    %a,b: upper - lower bounds
    %n: # of bisection
    %x: estimated solution
    %e: upper bound on the error
    %true_root: enable this when want to find the true error after having
    %found the true root
%     true_root = 5.6285;
    x=1;
    c = f(a); 
    d = f(b);
    if c*d > 0.0
        error("Function has same sign at both endpoints")
    end
    disp('       a         f(a)       b        f(b)       c       f(c)      error');
    for i=1:n
        x0=x;
        x = (a+b)/2;
        y = f(x);
        c = f(a); 
        d = f(b);
        e = abs((x-x0)/(x))*100;
        if y == 0.0
            a = x;
            b = x;
            break
        end
        if c*y<0
            b=x;
        else
            a=x;
        end
%      t = abs(((true_root-x)/true_root))*100;
    disp([a' c' b' d' x' y' e']);
    end
end
    

        