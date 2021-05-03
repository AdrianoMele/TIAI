% Nonlinear pendulum simulator
close all
clc

% Define time vector and solve differential equations
tspan = 1:1e-2:5;
[t,y] = ode45(@pendulumOdefun,tspan,[0;0;0.1;0]);

% Plot results
figure(1)
plot(t,y)
legend('x','v','\theta','\omega')

% Plot pedulum on cart
theta = y(:,3);
x     = y(:,1);

fh = figure(2);
for i = 1 : length(t)
  drawPendulum(fh,x(i),theta(i),l);
  ylim([-.5,.5])
  xlim([-.6 .6])
  pause(1e-3)
end


