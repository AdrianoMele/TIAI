%% Test inserimento bumpless
% Commutazione manuale-automatico a t=10s.
% Bolzern, es. 14.7

clear, close, clc

s = tf('s');
G = 1/(s+1);

Kp = 2;
Ki = 2;
Ti = Kp/Ki;

uman = 1;
UM = Inf; 

tswitch = 10;
out0 = sim('bumpyTransfer');
% out1 = sim('bumplessTransfer1');
out1 = sim('bumplessTransfer2');

%% Plot
figure(1), clf

plot(out0.y.time, out0.y.signals.values,'--b','linewidth',2);
hold on, grid on
plot(out1.y.time, out1.y.signals.values,'r','linewidth',2);
legend('senza bumpless', 'con bumpless')
