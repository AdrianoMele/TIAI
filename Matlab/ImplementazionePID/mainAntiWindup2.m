%% Schema anti wind-up #1
% Bolzern, es. 14.4-14.5

clear, close, clc

s = tf('s');
G = 1/(s+1);

Kp = 2;
Ki = 2;

Ti = Kp/Ki;

UM = Inf;
out0 = sim('windupIntegrale');

UM = 1.05;
out1 = sim('windupIntegrale');
out2 = sim('antiWindup2');


%% Plot
figure(1), clf

subplot(211)
plot(out0.u.time, out0.u.signals.values, '-+g', 'linewidth', 2);
hold on, grid on
plot(out1.u.time, out1.u.signals.values, '--b', 'linewidth', 2);
plot(out2.u.time, out2.u.signals.values, 'r', 'linewidth', 2);
legend('senza saturazione', 'con saturazione', 'con anti wind-up');
title('azione di controllo u(t)');

subplot(212)
plot(out0.y.time, out0.y.signals.values, '-+g', 'linewidth', 2);
hold on, grid on
plot(out1.y.time, out1.y.signals.values, '--b', 'linewidth', 2);
plot(out2.y.time, out2.y.signals.values, 'r', 'linewidth', 2);
plot(out1.r.time, out1.r.signals.values, 'k');
legend('senza saturazione', 'con saturazione', 'con anti wind-up');
title('variabile controllata y(t)');


%% Plot2
figure(2)
subplot(121)
plot(out1.u.time, out1.u.signals.values, 'r', 'linewidth', 2);
hold on, grid on
plot(out1.ureq.time, out1.ureq.signals.values, ':k', 'linewidth', 2);
plot(out1.ui.time, out1.ui.signals.values, '.-b', 'linewidth', 2);
plot(out1.e.time, out1.e.signals.values, '-+g', 'linewidth', 2);
legend('u','u_{req}','uscita integratore','errore')
title('senza anti wind-up');

subplot(122)
plot(out2.u.time, out2.u.signals.values, 'r', 'linewidth', 2);
hold on, grid on
plot(out2.ureq.time, out2.ureq.signals.values, ':k', 'linewidth', 2);
plot(out2.ui.time, out2.ui.signals.values, '.-b', 'linewidth', 2);
plot(out2.e.time, out2.e.signals.values, '-+g', 'linewidth', 2);
legend('u','u_{req}','uscita integratore','errore')
title('con anti wind-up');