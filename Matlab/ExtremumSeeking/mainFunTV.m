clear all
close all
clc

%% Funzione di costo e punto di minimo
f2    = 5; % derivata 2a
fcn   = @(theta,t) 6+f2/2*(theta-5-sin(t/4)).^2;

Tf = 100;
t  = 0:1e-2:Tf;
thetamin = 5+sin(t/4);


%% Parametri ES

%%% Lento, dimostrativo
a      = 0.2; % osc. amplitude
omega  = 50;  % probing freq.
k      = 5;   % integrator gain (aumentandolo il sistema diventa più veloce, ma può diventare instabile)
h      = 1;   % HPF cutoff (<< omega)

%%% Più veloce, oscillazioni più piccole
% a      = 0.01;
% omega  = 1e4;
% k      = 5e3;
% h      = 100;

% Initial guess
% theta0 = 10;
theta0 = 0;

%% Simulazione
open('simschemeFunTV.slx');
sim('simschemeFunTV.slx');

%% Plot e paragone con la dinamica "stimata" d_theta/d_t = -a*k*f2/2*theta (vedi slides)
figure(1)
ax1=subplot(211);
plot(J_sim.time, J_sim.signals.values,'linewidth',2)
grid on
ylabel('J(\theta)')
xlabel('t')

ax2=subplot(212);
plot(t,thetamin, 'r--','linewidth',2)
grid on, hold on
plot(theta_sim.time, theta_sim.signals.values,'linewidth',2)
legend('expected','simulated')
xlim('auto')
ylabel('\theta')
xlabel('t')

linkaxes([ax1,ax2],'x')