f = @(x) x.^2 - 9;
S = fzero(f,1) %find positive root
z = fzero(f,0) %find negative root
%% display all iteration with optimset
f = @(x) x.^2 - 9;
options = optimset('display','iter');
z = fzero(f,0,options);
%% set tolerance with optimset
f = @(x) x.^2 - 9;
options = optimset('tolfun', 1e-3);
y = fzero(f,0,options)
%% find root using 'roots'
S = roots([1 0 -9])