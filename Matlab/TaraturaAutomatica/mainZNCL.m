%% Esempio Z&N in anello chiuso
clear, close, clc

s = tf('s');
G = 5/(s+1)^3;

figure(1)
P = nyquistoptions;
P.ShowFullContour = 'off';
nyquistplot(G,P), grid on

%% Prova a ciclo chiuso
% Kp = 1.2;
Kp = 1.6;
sysCL = feedback(Kp*G, 1);
figure;
step(sysCL);

% Osservazione: il diagramma di nyquist passa per il punto critico
% quando Kp = Ku
figure(2)
nyquist(Kp*G), grid on

KU = Kp;

%% Calcolo TU
[y,t] = step(sysCL,1:5e-2:10);

ii = find(abs(diff(y))<3e-3);
figure(3)
plot(t,y,'linewidth',2), hold on, grid on
plot(t(ii),y(ii),'or');

TU = min(diff(t(ii)))*2;

%% Taratura PID
Kp = 0.6*KU;
Ti = TU/2;
Td = TU/8;

Ki = Kp/Ti;
Kd = Kp*Td;

N = 10;
C = Kp+Ki/s+Kd*s/1+s*Td/N;

[y1,t1] = step(sysCL,0:1e-3:15);
sysCL2 = feedback(C*G,1);
[y2,t2] = step(sysCL2,0:1e-3:15);
figure(4)
subplot(211)
plot(t1,y1,'linewidth',2);
title(['K_U = ' num2str(KU) ', T_U = ' num2str(TU)])
grid on
subplot(212)
plot(t2,y2,'linewidth',2);
title(['K_P = ' num2str(Kp) ', T_I = ' num2str(Ti) ', T_D = ' num2str(Td)])
grid on