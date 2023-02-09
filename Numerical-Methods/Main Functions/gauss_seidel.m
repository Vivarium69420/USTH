
n = 2; %number of eq
x1 = zeros(n);
tol = 0.01;
m = 5; %iter
lamda = 1.2; 
A = [10 -2 8;-3 12 9];
x1=[0 0];

k = 1;
while  k <= m %thay vao sau moi iter
    err = 0;
    for i = 1 : n
       s = 0;
       for j = 1 : n
          s = s-A(i,j)*x1(j);
       end
       s = (s+A(i,n+1))/A(i,i);
       err  = abs(s/(x1(i) + s));

       %x1(i) = x1(i) + s; 
       %if use lamda: 
       x1(i) = (1-lamda)*x1(i) + lamda*s;
       fprintf('\nThe error x%d iteration %d is: %.5f% \n',i, k, err);
       fprintf('\nx%d iteration %d is: %.5f% \n',i, k, x1(i));
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