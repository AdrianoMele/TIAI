%% Esempio 16.8
% Sistema con saturazione

% G = mu/(1+s)^3; 
% Il sistema è stabile per mu<8 (e.g. dal criterio di Nyquist)

clear, clc, close all

s = tf('s');
G = 1/(1+s)^3;
G = ss(G);

% Caratteristiche saturazione
X0 = 1;
E0 = X0;

%% #1: verifica stabilità con criterio del cerchio
% N appartiene alla classe Phi[0,1];
% Il minimo della parte reale di G(iw) è -0.25*mu

figure(1)
nyquist(G), grid on, hold on
plot([-1 -1], [-1000, 1000], 'r', 'linewidth', 2)


%% #2: calcolo funzione descrittiva
fd = @(E)X0/E0*2/pi.*(asin(E0./E)+E0./E.*sqrt((1-E0./E).^2));

E = 0:1e-1:20;
D = fd(E);
D(E<E0)=X0/E0;
figure(2)
plot(E,D,'linewidth',2);
xlabel('E'); ylabel('D(E)');
title('Funzione descrittiva saturazione')
grid on, hold on
mu = 16;
plot(2, fd(2),'or','linewidth',2)

%% Simulazione
sim('scheme16_8');
figure
plot(simOutput.time, simOutput.signals.values,'linewidth',2)
xlim([0 30])
xlabel('t'); ylabel('\epsilon')
grid on
