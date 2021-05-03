close all
clear all
clc

%% Define system and set ES parameters
% alpha = ampiezza oscillazioni
% omega = pulsazione oscillazioni
% gamma = guadagno integratore
% h     = polo HPF

%%% Nota: testare lo schema anche con funzionali di costo diversi (IAE, ITAE, ITSE)

sel = 4;

s = tf('s');
switch sel
  case 1  
    G = 1/(1+20*s)*pade(exp(-5*s),3); % Ritardo #1
    params = [4.2  9.2 2.31];  % Z&N, [Kp Ti Td]
    % params = [3.45  9.24 2.31];  % Funzione descrittiva
    alpha = [.1 1 .1];
    gamma = [50 500 50];
    omega = [.85 .85 .85]*pi;
    h = .5;
    tFinal = 100;
    nIter = 20;
    t0 = 10;
    
  case 2
    G = 1/(1+20*s)*pade(exp(-20*s),3); % Ritardo #2
    params = [1.33 31.0  7.74]; % Z&N
    % params = [1.2  30.19  7.54]; % Funzione descrittiva
    alpha = [.06 .3 .2];
    gamma = [1500 700 700];
    omega = pi*[.7 .7 .7];
    h = .8;
    tFinal = 400;
    nIter = 20;
    t0 = 40;
    
  case 3
    G = 1/(1+10*s)^8; % Polo ripetuto
    params = [1.1  75.9  19.0]; % Z&N
    % params = [1.1  75.5  18.9]; % Funzione descrittiva
    alpha = [.06 1.1 .5];
    gamma = [1000 2000 2000];
    omega = pi*[.5 .5 .5];
    h = .8;
    tFinal = 500;
    nIter = 20;
    t0 = 100;
    
  case 4
    G = (1-5*s)/((1+10*s)*(1+20*s)); % Zero a p.r. positiva
    params = [3.53 16.8  4.2]; % Z&N
    % params = [3.0  19.2  4.8]; % Funzione descrittiva
    alpha = [.025 .05 .05];
    gamma = [200 1300 1000];
    omega = pi*[.8 .8 .8];
    h = .5;
    tFinal = 100;
    nIter = 30;
    t0 = 20;
end

Kp = params(1);
Ti = params(2);
Td = params(3);
N = 100; % derivatore reale
Ki = Kp/Ti;
Kd = Kp*Td;

%% Initial simulation
sim simschemePID;
y_notOpt = y_plant;
% [~, iMax] = max(y_notOpt.signals.values);
% t0 = y_notOpt.time(iMax); % set t0 to the time of the first peak of the step response

%% Initialize variables
J_old = 0;      % initial value of the cost function (needed by the digital high-pass filter)
J_filt_old = 0; % initial value of filtered cost function (needed by the digital high-pass filter)
theta_hat_old = [Kp Ti Td]; % initial value of theta

%% Main cycle
J_history     = zeros(1,nIter);
theta_history = params;

for k = 1:nIter
  % Run simulation of the PID in closed loop and estimate the cost function (see the Simulink scheme)
  sim simschemePID;
  JJ = J.signals.values(end);
  J_history(k) = JJ;
  
  % High-pass filter on the cost function
  J_filt = -h*J_filt_old + JJ - J_old;
  
  % Update filter state
  J_filt_old = J_filt;
  J_old = JJ;
  
  % Cycle on the 3 PID gains
  u = [];
  for p = 1:3
    % p-th Modulation
    u(p) = J_filt*alpha(p)*cos(omega(p)*k);
    % p-th digital integrator
    theta_hat(p) = -gamma(p)*u(p)+theta_hat_old(p);
  end
  theta_history(k+1,:) = theta_hat;
  
  Kp = theta_hat(1) + alpha(1)*cos(omega(1)*k);
  Ti = theta_hat(2) + alpha(2)*cos(omega(2)*k);
  Td = theta_hat(3) + alpha(3)*cos(omega(3)*k);
  Ki = Kp/Ti;
  Kd = Kp*Td;
  
  % Update state of the integrators
  theta_hat_old = theta_hat;
end


%% Plot

figure(1)
plot(1:k,J_history,'*-','linewidth',2)
title('Cost function')

figure(2)
plot(y_notOpt.time, y_notOpt.signals.values, 'r', y_plant.time, y_plant.signals.values, 'b')
legend('ZN', 'ES')

figure(3)
plot(0:k, theta_history,'linewidth',2)
legend('Kp','Ti','Td')
