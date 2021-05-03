function imax = max_norm(a,b)
% imax = max_norm(a,b)
%  imax è 1 se norma(a)>norma(b), 0 se le norme sono uguali, 2
%  altrimenti.

if norm(a)<norm(b)
  imax = 2;
elseif norm(a)==norm(b)
  imax = 0;
else
  imax = 1;
end