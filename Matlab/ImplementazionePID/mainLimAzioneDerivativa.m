%% Test limitazione azione derivativa
% usiamo un impianto passa-basso e applichiamo l'azione derivativa
% su y(t) invece che su e(t).
% Essendo l'uscita di un passa-basso. la derivata di y(t) è 
% limitata.
% cfr. Bolzern, es. 14.1
close, clear, clc

s = tf('s');
G = 1/(s+1)^3;

Kp = 2;
Ki = 1;
Kd = 1;

Ti = Kp/Ki;
Td = Kd/Kp;
N = 5;

Kn = 0; % Senza rumore
b = 1;

% Senza limitazione
c = 1;
out1 = sim('limAzioneDerivativa');

% Con limitazione
c = 0;
out2 = sim('limAzioneDerivativa');

% Plot
figure(1), clf

subplot(211)
plot(out1.u.time, out1.u.signals.values, '--b', 'linewidth', 2);
hold on, grid on
plot(out2.u.time, out2.u.signals.values, 'r', 'linewidth', 2);
legend('senza limitazione', 'con limitazione');
title('azione di controllo u(t)');

subplot(212)
plot(out1.y.time, out1.y.signals.values, '--b', 'linewidth', 2);
hold on, grid on
plot(out2.y.time, out2.y.signals.values, 'r', 'linewidth', 2);
plot(out1.r.time, out1.r.signals.values, 'k');
legend('senza limitazione', 'con limitazione');
title('variabile controllata y(t)');

%% Test effetto rumore di misura
% Verifichiamo l'effetto di diverse scelte del parametro N
% sulla reiezione del rumore di misura.
% cfr. Bolzern, es. 4.2

Kn = 1; % Con rumore
N = 5;  % Per far girare di nuovo la stessa sezione
out3 = sim('limAzioneDerivativa');

N = 30;
out4 = sim('limAzioneDerivativa');


% Plot
figure(2), clf

subplot(211)
plot(out4.u.time, out4.u.signals.values, '--b', 'linewidth', 2);
hold on, grid on
plot(out3.u.time, out3.u.signals.values, 'r', 'linewidth', 2);
legend('N=30', 'N=5');
title('azione di controllo u(t)');

subplot(212)
plot(out4.y.time, out4.y.signals.values, '--b', 'linewidth', 2);
hold on, grid on
plot(out3.y.time, out3.y.signals.values, 'r', 'linewidth', 2);
plot(out3.r.time, out3.r.signals.values, 'k');
legend('N=30', 'N=5');
title('variabile controllata y(t)');