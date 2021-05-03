open('invPendStateFeedback.slx')

% Simula e salva i risultati
sim('invPendStateFeedback.slx')
ts     = simout.time;
xs     = simout.signals.values(:,1);
vs     = simout.signals.values(:,2);
thetas = simout.signals.values(:,3);
ws     = simout.signals.values(:,4);

% Plot comparativo con lsim
figure
subplot(411)
plot(ts,xs,t,x,'--');
title('x')
subplot(412)
plot(ts,vs,t,v,'--');
title('v')
subplot(413)
plot(ts,thetas,t,theta,'--');
title('\theta')
subplot(414)
plot(ts,ws,t,w,'--');
title('\omega')