%% ai,
clear all
clc
12^3+factorial(15)-sqrt(76)
%% aii,
clear all
clc
x = [1;2;3;4;5]
x'
%% bi,
clear all
clc
A = [1 2 3; 4 5 6; 7 8 9];
B = [1 1 6; 0 1 0; 0 0 1];
% bii,
C = A*B % Take the cross product of 2 matrix
D = A.*B % Multiply element-wise of 2 matrix
% biii,
disp('Eigen vector of D is:');
eig(D)
% biv
E = inv(A-B)
% bv
E(2,:) = [];
E(:,2) = [];
E
%% c,
clear all
x = 0:1:30;
y = 2*x + 6;
plot(x,y,'color','red');
title('Question 1 - c');
xlabel('x');
ylabel('y');
legend('y = 2*x+6','location','best');
