clear all
close all
clc

% define system
s = tf('s');
% sys = 1/(1+s)^3; delay=0;                   % simple example
sys = 1/(1+20*s); delay=5;                  % delay #1
% sys = 1/(1+20*s); delay=20;                 % delay #2
% sys = 1/(1+10*s)^8; delay=0;                % repeated pole
% sys = (1-5*s)/((1+10*s)*(1+20*s)); delay=0; % nonminimum-phase zero


% nyquist plot
figure()
nyquist(sys);

% init controller and NL
U = 5;
Kp = 0;
Ki = 0;
Kd = 0;


%% Retrieve parameters
sim('simscheme')

E = (max(simOutput.signals.values) - min(simOutput.signals.values))/2;

temp = simOutput.signals.values-mean(simOutput.signals.values);
ii = find(diff(sign(temp)));
T = (simOutput.time(ii(end)) - simOutput.time(ii(end-2)));
Kp_crit = 4*U/pi/E; % Guadagno critico
omega = 2*pi/T; % pulsazione


% Plot
figure
plot(simOutput.time, simOutput.signals.values)
hold on
plot(simOutput.time(ii(end-2)),simOutput.signals.values(ii(end-2)),'ro')
plot(simOutput.time(ii),simOutput.signals.values(ii),'ro')


%% Compute regulator parameters
choice = 'PID';
N = 10;
switch choice
    case 'P'
        Kp = 0.5*Kp_crit;
        Ki = 0;
        Kd = 0;
        PID = Kp;
    case 'PI'
        Kp = 0.45*Kp_crit;
        Ti = 0.8*T;
        Ki = Kp/Ti;
        Kd = 0;
        PID = Kp + Ki/s;
    case 'PID'
        Kp = 0.6*Kp_crit;
        Ti = 0.5*T;
        Td = 0.125*T;
        Ki = Kp/Ti;
        Kd = Kp*Td;
        PID = Kp + Ki/s + Kd*s/(1+s*Td/N);
end




sys2 = sys;
sys2.inputDelay = delay;
% sys2 = pade(sys2,5);
clsys = feedback(PID*sys,1);
figure(3), hold on, step(clsys)
