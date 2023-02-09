n = 4; %number of eq
x1 = zeros(n);%all in
tol = 0.01;
m = 3; %iteration
% lamda = input('Enter maximum number of iterations, lamda:  ');
A = [ 10 -1 2 0 6; -1 11 -1 3 25; 2 -1 10 -1 -11; 0 3 -1 8 15];
x1=[0 0 0 0];

k = 1;
while  k <= m
    err = 0;
    xnew = [0 0 0];
    for i = 1 : n
       s = 0;
       for j = 1 : n
          s = s-A(i,j)*x1(j);
       end
       s = (s+A(i,n+1))/A(i,i);
       err  = abs(s/(x1(i) + s));

       xnew(i) = x1(i) + s;
       fprintf('\nThe error x%d iteration %d is: %.5f% \n',i, k, err);
       fprintf('\nx%d iteration %d is: %.5f% \n',i, k, xnew(i));
    end
    
    for i = 1:n
        x1(i) = xnew(i);
    end
    if err <= tol
      break;
    else
      k = k+1;
    end
end

fprintf('\nSolution vector after %d iterations is :\n', k-1);
for i = 1 : n
  fprintf(' %11.8f \n', x1(i));
end