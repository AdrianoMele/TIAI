clear, close all, clc

%% Static car model: y = 2u
aModel  = 2;
aSystem = 1;           % parametric uncertainty

t = (0:1e-2:10)';
d = 10*sin(pi*t);      % disturbance

r = 100*ones(size(t)); % reference velocity

%% Open loop control
uOL = r/2;             % control action according to open loop model
yOL = aSystem*uOL + d; % system response

figure(1), hold on, grid on
plot(t,r,'--k','linewidth',2)
plot(t,yOL,'r','linewidth',2)
title('Open Loop response')
legend('reference','open loop')

%% Add closed loop controller
P   = aSystem;
K   = 100;             % high-gain proportional controller

yCL = (P*K)/(1+P*K)*r + 1/(1+P*K)*d;

figure(1)
plot(t,yCL,'b','linewidth',2)
title('Open vs Closed loop')
legend('reference','open loop','closed loop');

%% Add dynamics
s = tf('s');
P = 1/(s+1);

figure(2), hold on, grid on
[y,t] = lsim(P,r,t);
plot(t,r,'--k','linewidth',2)
plot(t,y,'linewidth',2);
% title(['Step response, U = ' num2str(r(1))])

%% Proportional controller on dynamical plant
out = sim('Pcontrol.slx');
uCLP = out.uCLP;
yCLP = out.yCLP;

figure(2)
plot(yCLP.time,yCLP.signals.values,'b','linewidth',2)
legend('reference', 'step response', 'P control')
set(gcf,'Position',[100 100 750 350]);

figure(3), hold on, grid on
plot(t,r,'k','linewidth',2)
plot(uCLP.time,uCLP.signals.values,'r','linewidth',2)
title('Control action')

%% PI controller
KP = 30;
KI = 20;
out = sim('PIcontrol.slx');
uCLPI = out.uCLPI;
yCLPI = out.yCLPI;

%% Plots
figure(2), hold on
plot(yCLPI.time,yCLPI.signals.values,'r','linewidth',2)
legend('reference', 'step response', 'P control','PI control')
set(gcf,'Position',[100 100 750 350]);

figure(3)
plot(uCLPI.time,uCLPI.signals.values,'b','linewidth',2)
title('Control action')
legend('u=r', 'P','PI')