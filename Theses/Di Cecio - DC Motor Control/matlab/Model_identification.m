clc, close all, clear all;

%% Estrazione ed elaborazione dati
tab = readtable('Spazio_50_50kHz.txt');
Vcc = 12;
duty_cicle = 50;
Vin = duty_cicle;
dt = 1e-3;                      % [s]
dx = 36*pi/180;                 % [rad]
z = tf('z',0.001);              %Variabile per FdT Discreta
s = tf('s');                    %Variabile per Fdt Continua
count = tab.Var2;

t = 0:dt:(numel(count)-1)*dt;   %Asse dei tempi [s]
theta = count*dx;               %Asse della posizione angloare [rad]

figure;
plot(t,theta,'LineWidth',2, 'Color','Black');
grid;
title('Posizione angolare [rad]');
xlabel('Tempo [s]');
ylabel('Posizione [rad]');
axis([0 0.15 0 50]);

%% Filtro Derivativo
T = 0.05;                   %Polo per la realizzabilità
D = s/(1+s*T);
Dd = c2d(D,0.001,'tustin');

%% Posizione angolare
figure;
% APPROSSIMAZIONE DEL MODELLO AL PRIMO ORDINE
polo = 0.2;
gain = 20;
set = [polo, gain];
parametri = fminsearch(@(x)ideal_tf1(x,t,theta,Vin),set);
tau = parametri(1); dcg = parametri(2);
G1 = dcg/(s*(1+s*tau));          %Funzione di trasferimento V->Theta
[y,ty] = step(G1,t);
y = y*Vin;
subplot(2,2,1);                 %Subplot per la posizione (1° ordine)
hold on;
plot(ty,y, 'Color', 'Green', 'LineWidth',2); %Stima
plot(t,theta, 'Color', 'Black'); %Misurazione
grid;
title('Posizione angolare (1° Ordine) [rad]');
xlabel('Tempo [s]');
ylabel('Posizione [rad]');
legend('Posizione misurata', 'Posizione stimata');
axis([0,0.07,0,20]);

% APPROSSIMAZIONE DEL MODELLO AL SECONDO ORDINE
polo1 = 100;
polo2 = 500;
alfa = 1000000;
beta = 0;
set2 = [polo1, polo2, alfa, beta];
parametri = fminsearch(@(x)ideal_tf2(x,t,theta,Vin),set2);
tau1 = parametri(1); tau2=parametri(2); a = parametri(3); b=parametri(4);
G2 = a/(s*((tau1+s)*(tau2+s)+a*b));      %Funzione di trasferimento V->Theta
[y,ty] = step(G2,t);
y = y*Vin;
subplot(2,2,3);
hold on;
plot(ty,y, 'Color', 'Green', 'LineWidth',2);
plot(t,theta, 'Color', 'Black'); %Misurazione
grid;
title('Posizione angolare (2° Ordine) [rad]');
xlabel('Tempo [s]');
ylabel('Posizione [rad]');
legend('Posizione misurata', 'Posizione stimata');
axis([0,0.07,0,20]);

%% Velocita angolare
% APPROSSIMAZIONE DEL MODELLO AL PRIMO ORDINE
subplot(2,2,2);
F = G1*D;                                    %Funzione di trasferimento V->Omega
[y,ty] = step(F,t);
y = y*Vin;
[w,tw] = lsim(Dd,theta,t,0);
hold on, plot(tw,w, 'Color', 'Black');      %Velocita angolare misurata
plot(ty,y, 'Color', 'Green', 'LineWidth',2);%Velocita angolare stimata

w_temp = interp1(tw,w,0.4:dt:0.6);          %Intervallo di tempo arbitrario a regime
reg  = mean(w_temp);                        %Valore di regime

reg_95perc = reg-((reg*5)/100);     
tw_95perc = tw(find(w > reg_95perc, 1));    %Tempo di assestamento al 5%
w_reg95perc = ones(1, length(tw)).*reg_95perc; 

hold on;
plot(tw,w_reg95perc, 'Color', 'Blue');
legend('Velocita misurata', 'Velocita stimata','Regime al 95%');
grid;
title('Velocita angolare (1° Ordine) [rad/s]');
xlabel('Tempo [s]');
ylabel('Velocità [rad/s]');
axis([0,0.5,0,400]);

% APPROSSIMAZIONE DEL MODELLO AL SECONDO ORDINE
subplot(2,2,4);
F = G2*D;                                    %Funzione di trasferimento V->Omega
[y,ty] = step(F,t);
y = y*Vin;
[w,tw] = lsim(Dd,theta,t,0);
hold on, plot(tw,w, 'Color', 'Black');      %Velocita angolare misurata
plot(ty,y, 'Color', 'Green', 'LineWidth',2);%Velocita angolare stimata

w_temp = interp1(tw,w,0.4:dt:0.6);          %Intervallo di tempo arbitrario a regime
reg  = mean(w_temp);                        %Valore di regime

reg_95perc = reg-((reg*5)/100);     
tw_95perc = tw(find(w > reg_95perc, 1));    %Tempo di ssestamento al 5%
w_reg95perc = ones(1, length(tw)).*reg_95perc; 

hold on;
plot(tw,w_reg95perc, 'Color', 'Blue');
legend('Velocita misurata', 'Velocita stimata','Regime al 95%');
grid;
title('Velocita angolare (2° Ordine) [rad/s]');
xlabel('Tempo [s]');
ylabel('Velocità [rad/s]');
axis([0,0.5,0,400]);
