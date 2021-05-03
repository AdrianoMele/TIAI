clear all
close all
clc

%% Funzione di costo e punto di minimo
f2    = 5; % derivata 2a
fcn   = @(theta) 6 + f2/2 * (theta-5).^2;
theta = -10:0.1:10;
[m,i]    = min(fcn(theta));
thetamin = theta(i);

figure(1)
plot(theta, fcn(theta),'linewidth',2)
grid on, hold on
plot(thetamin, m, 'r*','linewidth',2)
xlabel('\theta')
ylabel('J(\theta)')

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
open('simschemeFun.slx');
sim('simschemeFun.slx');

%% Plot e paragone con la dinamica "stimata" d_theta/d_t = -a*k*f2/2*theta (vedi slides)
figure(1)
plot(theta_sim.signals.values(end), J_sim.signals.values(end), '^k','linewidth',2);

figure(2)
ax1=subplot(211);
plot(J_sim.time, J_sim.signals.values,'linewidth',2)
grid on
ylabel('J(\theta)')
xlabel('t')

ax2=subplot(212);
plot(theta_sim.time, theta_sim.signals.values - thetamin,'linewidth',2)
grid on, hold on
plot(theta_sim.time, (theta0-thetamin)*exp(-(a^2*k*f2/2)*theta_sim.time), '--r','linewidth',2)
legend('simulated','expected (exp)')
xlim('auto')
ylabel('\theta - \theta^*')
xlabel('t')

linkaxes([ax1,ax2],'x')

