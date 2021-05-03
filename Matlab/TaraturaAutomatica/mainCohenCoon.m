%% Esempio: Cohen-coon e IAE
clear, close, clc
reg1 = 'CC'; % CC o ZN

% Inizializzazione sistema e calcolo risposta indiciale
% G = tf([1],[1 1.9 1]);
G = tf(10,[0.01 1.01 1]); % esame 25/06
dt = 1e-3;
[y,t] = step(G,0:dt:10);

plot(t,y,'linewidth',2)
hold on, grid on
plot(t,t*0+y(end),'k')
title('Step response')

% Ricerca flesso
iflesso = find(diff(diff(y))<0,1);
tflesso = t(iflesso);
plot(tflesso,y(iflesso),'or')

% Calcolo tangente
m = (y(iflesso+1)-y(iflesso))/dt;
tau = tflesso - y(iflesso)/m;
plot(tau,0,'or')

% Calcolo costante di tempo
T = tflesso + (y(end)-y(iflesso))/m;
plot(T,dcgain(G),'or');
plot([tau, T], [0 dcgain(G)], '--k');

% Calcolo guadagno statico
mu = y(end)/1;

%% Calcolo controllore PID CC

if strcmp(reg1,'ZN')% Z&N
  Kp = 1.2*T/(mu*tau);
  Ti = 2*tau;
  Td = 0.5*tau;
elseif strcmp(reg1, 'CC') % Cohen Coon
  Kp = (1.35/(tau/T) + 0.27)/mu;
  Ti = (2.5*(tau/T)*(1+tau/T/5)/(1+0.6*(tau/T))) * T;
  Td = (0.37*(tau/T)/(1+0.2*(tau/T)))*T; 
end


Ki = Kp/Ti;
Kd = Kp*Td;

N = 10;

s = tf('s');
PID = Kp + Ki/s + Kd*s/(1+s*Td/N);

clSys = feedback(G*PID,1);
figure(2)
hold on
step(clSys)

%% Calcolo controllore PID IAE
Kp = (1.086*(tau/T)^-0.861)/mu;
Ti = T/(0.740-0.130*(tau/T));
Td = (0.348*(tau/T)^0.914)/T;

Ki = Kp/Ti;
Kd = Kp*Td;

N = 10;

s = tf('s');
PID = Kp + Ki/s + Kd*s/(1+s*Td/N);

clSys = feedback(G*PID,1);
figure(2)
hold on
step(clSys),grid on
legend(reg1,'IAE')




