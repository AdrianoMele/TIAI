%% Esempio wind-up
% cfr. Bolzern, es. 14.3

clear, close, clc

s = tf('s');
G = 1/(s+1);

Kp = 0;
Ki = 2;

UM = Inf; % senza saturazione
out1 = sim('windupIntegrale');

UM = 1.05; % con saturazione
out2 = sim('windupIntegrale');

% Plot
figure(1), clf

subplot(211)
plot(out1.u.time, out1.u.signals.values, '--b', 'linewidth', 2);
hold on, grid on
plot(out2.u.time, out2.u.signals.values, 'r', 'linewidth', 2);
plot(out2.ureq.time, out2.ureq.signals.values, '.r', 'linewidth', 2);
legend('senza saturazione', 'con saturazione','richiesta');
title('azione di controllo u(t)');

subplot(212)
plot(out1.y.time, out1.y.signals.values, '--b', 'linewidth', 2);
hold on, grid on
plot(out2.y.time, out2.y.signals.values, 'r', 'linewidth', 2);
plot(out1.r.time, out1.r.signals.values, 'k');
legend('senza saturazione', 'con saturazione');
title('variabile controllata y(t)');

figure(2)
plot(out2.u.time, out2.u.signals.values, 'r', 'linewidth', 2);
hold on, grid on
plot(out2.ureq.time, out2.ureq.signals.values, '--b', 'linewidth', 2);
plot(out2.e.time, out2.e.signals.values, '-+k', 'linewidth', 2);
legend('controllo','richiesta','errore');
title('azione di controllo u(t)');

