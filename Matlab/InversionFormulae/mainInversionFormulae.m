clear, close all, clc
run parametri

% Un motore elettrico DC può essere modellato come:
% 
% L*di/dt = -R*i  - Kv*w + V
% J*dw/dt = -Kt*i -  b*w + Tr
% 
% Kv*w è il termine di forza contro-elettromotrice
% Kt*i è la coppia meccanica
% Se il motore è compensato, Kv=Kt
% 
% J è il momento di inerzia, L l'induttanza di armatura, R la
% resistenza di armatura, b l'attrito, Va la tensione di ingresso
% Tr la coppia resistente (disturbo da reiettare)

s = tf('s');

A = [-R/L, -k/L; k/J, -sigma/J];
B = [1/L; 0];
% C = [k, 0];           % considero come uscita la coppia
C = [0, 1];           % considero come uscita la velocità
D = 0;
disp('Autovalori della matrice dinamica A:')
eig(A)              % autovalori matrice dinamica

disp('F.d.t. del processo:')
G = tf(ss(A,B,C,D))   % tf processo

figure(1)
subplot(2,2,1)
margin(G), grid

%% Sintesi controllore TC con formule di inversione
wg = 300;
PM = 60;

% Calcolo modulo e fase del sistema a ciclo aperto a w=wg
[M, P] = bode(G, wg); 
Mg     = wg/M;
phig   = (PM-90-P)*pi/180;

Kp_inv = Mg*sin(phig)/wg;
Ti_inv = tan(phig)/wg;
Ki_inv = Kp_inv/Ti_inv;

disp('Regolatore sintetizzato mediante formule di inversione:')
C_inv = Kp_inv+Ki_inv/s

L_inv = G*C_inv;        % tf di anello
% margin(L_inv)

% fdt a ciclo chiuso
figure(1)
subplot(2,2,2)
margin(L_inv), grid
subplot(2,2,3:4)
F = feedback(L_inv,1);
step(F), grid, title('Risposta indiciale T.C.')


%% Discretizzazione del processo
T = 0.001;        % sampling period = 1ms

z = tf('z', T);
Gz = c2d(G, T, 'zoh'); % discretizzazione del processo con passo di campionamento T e metodo ZOH

figure(2)
subplot(2,2,1)
margin(Gz), grid


%% Sintesi controllore digitale
wg = 300;    % rad/s
PM = 60;      % gradi     
Wg = tan(wg*T/2);

[MD, PD] = bode(Gz, wg); 
Mg       = Wg/MD;
phig     = (PM-90-PD)*pi/180;

Ktpz_inv = Mg*sin(phig)/Wg;
Ttiz_inv = tan(phig)/Wg;
Ktiz_inv = Ktpz_inv/Ttiz_inv;

disp('Regolatore digitale:')
Ctz_inv = (Ktpz_inv+Ktiz_inv*(z+1)/(z-1))

Lz_inv = Gz*Ctz_inv;          % tf di anello

% fdt a ciclo chiuso
figure(2)
subplot(2,2,2)
margin(Lz_inv), grid
figure(2)
subplot(2,2,3:4)
Fz = feedback(Lz_inv,1);
step(Fz), grid, title('Risposta indiciale T.D.')



 
