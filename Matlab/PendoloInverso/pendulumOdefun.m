function yp = pendulumOdefun(~,y,K)
% Pendulum dynamics
global m M g l b

x     = y(1);
v     = y(2);
theta = y(3);
w     = y(4);

if nargin == 2
  F = 0;
else
  F = -K*y; % state feedback
end

yp = [v;
                     (-m*w^2*l*sin(theta) + m*g*sin(theta)*cos(theta) - b*v + F)/(m+M-m*cos(theta)^2);
      w;
      cos(theta)/l * (-m*w^2*l*sin(theta) + m*g*sin(theta)*cos(theta) - b*v + F)/(m+M-m*cos(theta)^2) + g/l*sin(theta)];
end