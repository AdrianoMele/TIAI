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
out2 = sim('antiWindup1');



% Plot
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