% Simulatore non lineare
% close all
% clc

% Vettore tempo e algoritmo di risoluzione equazioni differenziali
tspan = 0:1e-2:5;
[tnl,y] = ode45(@(t,y)pendulumOdefun(t,y,K),tspan,[0;0;theta0;0]);

% Estrai risultati e confronta con il caso linearizzato
xnl     = y(:,1);
vnl     = y(:,2);
thetanl = y(:,3);
wnl     = y(:,4);

figure(1)
subplot(411)
plot(tnl,xnl,'linewidth',2);
hold on
plot(t,x,'--','linewidth',2);
title('x')
subplot(412)
plot(tnl,vnl,'linewidth',2);
hold on
plot(t,v,'--','linewidth',2);
title('v')
subplot(413)
plot(tnl,thetanl,'linewidth',2);
hold on
plot(t,theta,'--','linewidth',2);
title('\theta')
subplot(414)
plot(tnl,wnl,'linewidth',2);
hold on
plot(t,w,'--','linewidth',2);
title('\omega')

% Plot pendolo e carrello
fh = figure(2);
for i = 1 : 20 : length(tnl)
  drawPendulum(fh,xnl(i),thetanl(i),l);
  ylim([-.5,.5])
  xlim([-.6 .6])
  title(['t = ' num2str(tnl(i)) 's'])
  pause(1e-3)
end


