% a,
A =zeros(3,3);
% b,
v =ones(1,3);
A = diag(v);
% c,
B = A'
% d,
A+B;
A-B;
A*B;
A.*B;
%index all elem i a particular dimension
A(:,3) = []; %taking at column 3
A(3,:) = []; %taking at row 3
